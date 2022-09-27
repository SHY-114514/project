# C++ 从入门到入土
### 1、编译过程
- 预编译
源代码编写完成后，通过 `gcc -E hello.c -o hello.i` 对源文件进行预编译，预编译阶段，gcc 为我们将头文件导入到源代码中，并且替换所有的宏定义、去除所有的注释，在预编译过程中，不会检查源代码的语法错误，在此阶段，条件编译会进行

~~~c
int main(void){
    #if abc
    printf("Hello World!\n");
    #endif
    return 0;
}
~~~

gcc 会将这段代码编译成

~~~c
int main(void){
    
    

    return 0;
}
~~~
可以看出，printf() 函数没有被预编译
如果在预编译命令中加入 `-D abc` ，则 printf() 函数会被预编译

- 编译

该过程将预编译之后的文件编译成汇编文件 `gcc -S hello.i -o hello.s` ，在这个阶段， gcc 会检查语法错误，若存在语法错误，则无法通过编译

- 汇编

将汇编文件(.s)编译成二进制文件(.o) `gcc -c hello.s -o hello.o`

- 链接

`gcc hello.o -o hello.exe` 设置二进制文件运行环境、堆栈、链接其他库等