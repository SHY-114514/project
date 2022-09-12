# 设计模式
### 1、单例模式

一个类只有一个实例，并且保留一个全局访问点

优点：节省内存、CPU 资源，严格控制全局变量以及类似数据库连接池及其工具类之类的不需要多个实例的对象

- 懒汉模式

~~~java
//单例模式实例化对象
public class LazySingleton{
    //volatile 关键字可以防止 CPU 重排 JVM 指令顺序，加强线程安全
    private volatile static LazySingleton instance;
    //私有化构造方法
    private LazySingleton(){}
    //全局访问接口
    public static LazySingleton getInstance(){
        if{null == instance}{//双重加锁，保证线程安全和高效运行
            synchronized(LazySingleton.class){
                if(null == instance){
                    instance = new LazySingleton();
                }
            }
        }
        return instance;
    }
}
~~~

- 饿汉模式

~~~java
public class HungrySingleton{
    //直接静态实例化一个对象
    private static HungrySingleton instance = new HungrySingleton();
    //私有化构造方法
    private HungrySingleton(){}
    //全局接口
    public static HungrySingleton getInstance(){
        return instance;
    }
}
~~~

饿汉模式只能够被动实例化对象，可以考虑使用内部类进行主动初始化(懒加载模式与饿汉模式结合)
~~~java
public class HungrySingleton{
    //私有化构造方法
    private HungrySingleton(){}
    //在内部类中实例化对象
    private class InnerClass{
        private static HungrySingleton instance = new HungrySingleton();
    }
    //全局接口，返回内部类中实例化的对象
    public static HungrySingleton getInstance(){
        return InnerClass.instance;
    }
}
~~~

