#include<iostream>
using namespace std;

/*
多态
    在基类的函数前加上virtual关键字 在派生类中重写该函数 运行时会指向对对象实际类型来调用相对应的函数
    如果对象类型是派生类 就调用派生类函数 如果是基类就调用基类函数
*/
class Base
{
public:
//虚函数
    virtual void fun(){
        cout << "Base::fun()" << endl;
    }
};

class Son1 : public Base{
    virtual void fun() override{
        cout << "Son1::fun()" << endl;
    }
};

class Son2 : public Base{

};

int main()
{
    // Son1::fun()
    // Base::fun()输出结果
    /*
    子类继承并重写了基类的函数 
    虚表和虚基表指针
    虚表 虚函数表 virtual关键字修饰方法时 编译器会自动生成虚表
    虚表指针 含有虚函数的类实例化对象 对象地址的前四个字节存储的指向虚表的指针
    派生类没有对基类的虚函数进行重写时 派生类的虚表指针指向基类的虚表 重写了就会指向自身的虚表 
    派生类有自己的虚函数时 在自己的虚表中将该虚函数的地址添加在后面
    */
    Base base2;
    Base* base = new Son1;
    base->fun();
    base = new Son2;
    base->fun();
    delete base;
    base = nullptr;

    system("pause");
    return 0;
}