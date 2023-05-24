#include"heard.h"
/*
纯虚函数
    没有实现的函数 只是声明 通过赋值0 来声明纯虚函数 没有函数体
含有纯虚函数的类就是抽象类
抽象类只能作为基类来派生新类使用 不能创建抽象类的对象 抽象类的指针和引用

*/

//抽象类
class Base{
public:
    virtual void show() = 0;
    void g() { 
        this->show(); 
    }
    Base(){
        cout << "Base()" << endl;
    }
    virtual ~Base(){
        cout << "Base::~Base()" << endl;
    }
};

class Son : public Base{
public:
    void show(){
        cout << "Son::show()" << endl;//重写函数
    }
    Son(){
        cout << "Son()" << endl;
    }
    ~Son(){
        cout << "~Son()" << endl;
    }
};

int main()
{
    Son s;
    s.show();
    //s.g();
    Base* b = new Son();
    b->show();
    delete b;

    system("pause");
    return 0;
}
