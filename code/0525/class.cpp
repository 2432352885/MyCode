#include <iostream>
using namespace std;

class A
{
public:
    A(){
         tmp();
    }

    virtual ~A(){
        cout << "~A()" << endl;
    }

    virtual void tmp(){
        cout << "this is parent" << endl;
    }
};

class B : public A
{
public:
    void tmp() override{
        cout << "this is son" << endl;
    }

    B(){
        tmp();
    }

    ~B() override {
        cout << "~B()" << endl;
    }
};

int main()
{
// this is parent  a的构造
// this is parent  
// this is son     b的构造 先调用父类的构造 之后调用子类的构造
// Press any key to continue . . .
// ~B()     先调用子类的析构
// ~A()     调用父类的析构
// ~A()     a的析构
    A a;
    B b;


    system("pause");
    return 0;

}