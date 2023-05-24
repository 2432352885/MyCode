#include<iostream>
using namespace std;

class A
{
public:
    int num1;
    int num2;
public: 
    A(int a, int b) : num1(a), num2(b){};
    A(const A& a)
    {
        num1 = a.num1;
        num2 = a.num2;
    };
    
    //重载=操作符
    A& operator= (const A& a)
    {
        num1 = a.num1;
        num2 = a.num2;
        return *this;

    };
    ~A(){};
};



int main()
{
    A a(1,1);
    A a1 = a;//拷贝构造 调用构造函数
    A b(a);
    b = a;//赋值操作 

    system("pause");
    return 0;


}