### 本周完成工作

1、C语言 - 算法题

2、Java - 设计模式

3、Python - Flask


### 本周工作总结

1、C语言
- 做了几道 PTA 新题

- 复习了一下上周的几种排序


2、Java

- 完善了单例模式，使得别人无法通过反射和反序列化拿到不同的实例

为了防止其他代码通过反射拿到构造函数、修改构造函数的访问权限，可以
~~~java
public class Singleton{
    private static Singleton instance;
    private static String name = "张三";
    private Singleton(){
        if(instance != null)
            throw new RuntimeException("单例模式不允许产生多个实例");
    }
    static class SingletonHolder{
        public static Singleton ins;
        public SingtonHolder(){
            ins = new Singleton();
        }
    }
    public Singleton getInstance(){
        instance = SingletonHolder.ins;
        return instance;
    }
}
~~~

为了防止别人通过反序列化拿到不同的实例，可以添加一个 `serialVersionUID` 属性以及在 `readResolve()` 方法中返回 `instance` ,这样别人通过反序列化拿到的还是当前这个实例

- 学习了抽象工厂模式，抽象工厂模式将固定或常用的属性抽象出来，放到抽象类中，然后写一个工厂类去进行调度、管理类的创建和方法的调用


3、Python

- flask 框架搭建好之后，这周主要解决了多线程问题（没有使用其他框架），自己定义了一个线程池，对线程进行管理，限制并发4线程（我自己的服务器是4线程）

- 在 flask 中搭建了通用爬虫（现在还无法正常使用），主要是数据库没搭建起来

### 下周工作安排

1、C语言继续刷算法题或者复习之前的算法题

2、Java 继续学习简单、抽象工厂模式

3、Flask 解决调度问题，可能要写一个调度管理器，针对服务器集群（docker多创建的几个环境，其实还是在一台服务器上，主要是想玩一下多服务器的调度）