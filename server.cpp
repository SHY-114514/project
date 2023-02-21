#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 1024		//缓冲区大小
#define SERVER_IP_ADDR "127.0.0.1" //服务器IP地址
#define SERVER_PORT 80			   //服务器端口号

using namespace std;

//日志打印工具
void log(string msg){ cout << "【INFO  】 " << msg << endl; }	//普通级别
void err(string msg){ cout << "【ERROR 】 "+msg << endl; exit(1); }		//errOR级别，程序出现严重问题，强制退出


SOCKET initsocket()
{
	log("初始化动态链接库 ...");
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		err("动态链接库初始化失败");
	log("创建套接字 ...");
	SOCKET ServerSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSock == INVALID_SOCKET)
		err("套接字创建失败");
	log("配置IP、绑定端口 ...");
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr, 0, sizeof(struct sockaddr)); //每一个字节都用0来填充
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(SERVER_PORT);
	ServerAddr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDR);
	if (bind(ServerSock, (SOCKADDR *)&ServerAddr, sizeof(struct sockaddr)) == SOCKET_ERROR)
		err("端口绑定失败");
	return ServerSock;
}

void getfile(SOCKET s, string url)
{
	string file = "./resources/" + url.substr(url.find_last_of('.') + 1) + url;
	cout << "【INFO  】 响应" <<file << endl;
	FILE *fp = fopen( file.c_str(), "r");
	if (fp == NULL){ cout << "打开文件失败！\n"; return; }
	char temp[1024] = "";
	do
	{
		fgets(temp, 1024, fp);
		send(s, temp, strlen(temp), 0);
	} while (!feof(fp));
	fclose(fp);
}

void handlerequest(SOCKET s, char *msg)
{
	char method[7], url[100], version[10];
	sscanf(msg, "%s %s %s", method, url, version);
	cout <<"请求" << url << endl;
	if (strcmp(method, "GET") == 0)
		getfile(s, url);
	else if (strcmp(method, "POST") == 0)
	{
		cout << "接收到POST请求" << url << endl;
	}
}

int main()
{
	//实现主要功能
	SOCKET ServerSock, client;
	struct sockaddr_in ClientAddr;
	int rval, length;
	char revbuf[BUF_SIZE];

	log("启动 Web 容器 ...");
	ServerSock = initsocket();
	log("Web 容器启动成功\n");

	system("start http://localhost:80/index.html");	//自动打开网站首页

	while (1)
	{
		log("监听请求 ...");
		if (listen(ServerSock, 10) == SOCKET_ERROR)
			err("失败");

		/* 接受客户端请求建立连接 */
		length = sizeof(struct sockaddr);
		if ((client = accept(ServerSock, (SOCKADDR *)&ClientAddr, &length)) == INVALID_SOCKET)
			err("连接客户端失败");
		// char tmp = ";";
		cout << "【INFO  】 " << inet_ntoa(ClientAddr.sin_addr) << ":" << ntohs(ClientAddr.sin_port);

		/* 接收客户端请求数据 */
		memset(revbuf, 0, BUF_SIZE); //每一个字节都用0来填充
		rval = recv(client, revbuf, BUF_SIZE, 0);
		revbuf[rval] = 0x00;
		if (rval <= 0){
			cout << "接收客户端数据失败" << endl;
			closesocket(client);
			break;
		}
		handlerequest(client, revbuf);
		closesocket(client);
		cout << endl << endl;
	}

	closesocket(ServerSock); //关闭套接字
	WSACleanup();			 //停止Winsock

	return 0;
}