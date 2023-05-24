#include "heard.h"

/*
析构函数一般写成虚函数
    类的多态性 基类指针可以指向派生类的对象 删除基类的指针 就会调用该指针指向的派生类析构函数
    而派生类析构函数又自动调用基类的析构函数 整个派生类对象都会被完全释放

    如果析构函数不被声明成虚函数 编译器静态绑定 删除基类指针时 只会调用基类的析构函数而不调用派生类
    的析构 造成派生类对象析构不完全 造成内存泄漏 
    当基类操作派生类时防止在析构时防止只析构基类而不析构派生类的情况发生


    析构函数可以是纯虚函数 含有纯虚函数的类是抽象类 此时不能被实例化 派生类可以根据自己的要求重新改写基类中
    的纯虚函数

    虚函数表 是全局共享元素 仅有一个 编译时构造完成 
    虚函数表类似一个数组 类对象中存储vptr指针 指向虚函数表
    虚函数表类似静态成员变量 可能在全局数据区 微软 常量段  虚函数 代码段
*/

//没有将基类析构定义成虚函数时
// Base::Base()
// Son::Son()
// Base::~Base()

//虚函数后
// Base::Base()
// Son::Son()
// Son::~Son()
// Base::~Base()

class Base{
public:    
    Base(){
        cout << "Base::Base()" << endl;
    }

    virtual ~Base(){
        cout << "Base::~Base()" << endl;
    }
};

class Son : public Base{
public:
    Son(){
        cout << "Son::Son()" << endl;
    }

    ~Son(){
        cout << "Son::~Son()" << endl;
    }
};

int main()
{
    Base* a = new Son();
    delete a;
    a = nullptr;

    system("pause");
    return 0;
}