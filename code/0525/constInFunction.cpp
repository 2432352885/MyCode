#include<iostream>
using namespace std;

class A
{
public:
    void func() const{
        //a = b;//报错 函数后面加上const之后 类内部的成员函数 不能修改类的成员
        //只能去读取数据
        cout << this->a << endl;
    }
private:
    int a = 10;
};

int main()
{
    A a;
    a.func();

    system("pause");
    return 0;
}