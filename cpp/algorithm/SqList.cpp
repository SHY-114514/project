#include <iostream>
#include<string>

#define N 10
#define OK 1
#define ERROR 0

using namespace std;

typedef int Status;
typedef struct{
    string name;
    string author;
} DataType;

typedef struct
{
    DataType *datas;
    int length;
} SqList;

Status InitList(SqList &L)
{
    L = *(new SqList());
    L.length = 0;
    L.datas = new DataType[N];
    return OK;
}

Status Insert(SqList &L, DataType data, int position)
{
    if (position <= 0 || position > L.length + 1 || L.length > N - 1)
        return ERROR;
    int p = L.length;
    while (p > 0 && p >= position)
    {
        L.datas[p] = L.datas[p - 1];
        --p;
    }
    L.datas[p] = data;
    ++L.length;
    return OK;
}

Status Delete(SqList &L,int position)
{
    if(position < 1 || position > L.length)
        return ERROR;
    for(int p = position;p < L.length;p ++)
        L.datas[p -1] = L.datas[p];
    -- L.length;
    return OK;
}

void PrintList(SqList &L)
{
    int i = 0;
    while (i < L.length)
        cout << L.datas[i].name << "\t" << L.datas[i ++] << endl;
}

int main(void)
{
    SqList L;
    cout << "初始化测试" << endl;
    if(!InitList(L))
        cout << "初始化失败" << endl;
    cout << "初始化成功" << endl;
    cout << "插入测试" << endl;
    for (int i = 0; i < 6; i++){
        string name = "书籍"+to_string(i);
        string author = "作者" + to_string(i);
        DataType data = {name,author};
        if(Insert(L, data, i + 1))
            cout << "插入失败" << endl;
    }
    PrintList(L);
    cout << "删除测试" << endl;
    if(!Delete(L,3))
        cout << "删除失败" << endl;
    PrintList(L);
    return 0;
}
