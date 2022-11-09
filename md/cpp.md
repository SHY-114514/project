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

### 2、类

##### 1）访问权限

| 权限 | 说明 |
|-----|-----|
|public|公共的，类的内部和外部都可以访问|
|protected|受保护的，类内部可以访问，外部禁止访问，子类可以访问|
|private|私有的，类内部可以访问，外部禁止访问，子类禁止无法访问|

<span style="color:red">struct 与 class 默认访问权限不同，struct 默认访问权限为 public ,而 class 默认访问权限为 private</span>

##### 2）实例化

~~~cpp
class MyClass{
public:
    void hello(){
        cout << "Hello,this is your frist class demo" << endl;
    }
}
int main(void){
    MyClass myclazz;
    myclazz.hello();
    return 0;
}
~~~

这是无参构造实例化类，可以通过重载构造函数进行有参构造在实例化时传入一些参数

~~~cpp
class Person{
public:
    string name;
    int age;
    //重载构造函数
    Person(string name,int age){
        this.name = name;
        this.age = age;
    }
}
//实例化对象
Person p1("张三","17");
~~~

##### 3）构造函数与析构函数
- 构造函数在类进行实例化时自动调用的函数
- 析构函数在类被销毁前自动调用的函数


<span style="color:yellow">构造函数与析构函数如果未定义，则编译器会自动为你添加空的构造函数和析构函数，并且在初始化和销毁时自动调用</span>


构造函数函数名与类名相同，无需写返回值类型，有参数列表，可以被重载

析构函数函数名为 `~` 加类名，无需写返回值类型，无参数列表，因此不可重载


~~~cpp
class MyClass{
public:
    MyClass(){
        cout << "我是构造函数" << endl;
    }
    ~MyClass(){
        cout << "我是析构函数" << endl;
    }
}
~~~

构造函数的分类

- 按参数分类：有参构造、无参构造

- 按类型分类：普通构造、拷贝构造

调用方式：括号法、显式法、隐式转换法

~~~cpp
class MyClass{
public:
    int a;
    //普通构造
    MyClass(){} //无参构造
    MyClass(int a){this.a=a;} //有参构造
    //拷贝构造，需要传入引用并使用 const 关键词进行修饰
    MyClass(const Person &p){this.a=p.a;}
    ~MyClass(){cout<<"析构函数被调用";}
}

MyClass p1; //调用无参构造函数不可以添加括号，否则编译器会认为这行代码是函数的声明
//括号法
MyClass p2(10); //有参构造实例化对象
MyClass p3(p2); //拷贝构造
//显式法
MyClass p4 = MyClass(10);
MyClass(20);    
/*匿名对象，当前行执行完之后系统立即释放，（这里先打印‘析构函数被打印’，再打印‘ABC’）
不要使用拷贝构造函数初始化匿名对象Person(p3),编译器认为Person(p3)等价于Person p3,p3在上方已经被定义了，所以编译器会报错*/
cout << "ABC" << endl;
//隐式转换法
Person p5 = 10; //自动匹配对应的有参构造函数并传值调用
~~~

