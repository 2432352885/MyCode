/*
重载(overload)
    在一定范围定义中的同名成员函数才存在在重载关系 主要特点是函数名相同 参数类型和数目不同
重写/覆盖(override)
    重写是指在派生类中覆盖基类中的同名函数
    重写就是重写函数体 要求基类函数必须是虚函数并且
    和基类的虚函数有同样的参数个数 相同的参数类型 相同的返回值
隐藏(hide)
    派生类中的函数屏蔽了基类中的同名函数
    两个函数参数相同 但是基类函数不是虚函数 
*/

#include<iostream>
using namespace std;

class A
{
public:
//overload
    void fun(int a){
        cout << "int a = " << a << endl;
    }
    void fun(char b){
        cout << "char fun b = " << b << endl;
    }
    void fun(int a, int b){
        cout << "int a = " << a << " int b = " << b << endl;
    }
    virtual void fun(int a, char c){
        cout << " A int and char" << endl;
    }

};

class B: public A
{
public:
//override
    void fun(int a, char c) override{
        cout << "B int and char" << endl;
    }

    void fun(char* c){
        cout << "hide fun for overload" << endl;
    }

    void fun(int a){
        cout << "hide fun override" << endl;
    }
};

int main()
{
    B b;
    char* c = nullptr;
    b.fun(10);
    b.fun(c);
    b.fun(10, 'b');
    b.A::fun(10, 9);


    system("pause");
    return 0;
}