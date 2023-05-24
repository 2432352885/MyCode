#include<iostream>
using namespace std;

//override重载
//final不希望某个类被继承或者不希望某个虚函数被重写 
class A
{
    virtual void foo();
};

class B : public A
{
    //void foo(); //OK
   // virtual void foo(); // OK
   void foo() override; //OK
};

class Base
{
    virtual void foo();
};

class C : public Base
{
    void foo() final;
};

// class E : public C
// {
//     void f00() override;//final就不能重写继承了
// };
int main()
{
    
    system("pause");
    return 0;
}