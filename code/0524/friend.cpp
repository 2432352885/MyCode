#include"heard.h"
/*
友元
    提供了不同类的成员函数之间 类的成员函数和一般函数之间进行数据共享的机制
    通过友元 一个类外函数和另一个类的成员函数能够访问类中的私有成员和保护成员
    破坏了类的封装性和数据的隐蔽性 导致程序的可维护性变差

注意
    友元关系是不能被继承的
    友元关系是单向的
    友元关系不具有传递性
*/
class A{
public:
    friend void set_show(int x, A& a);
    friend class C;
    A() : data(0) {};
private:
    int data;

};

class C{
public:
    void set_show(A& a){
        cout << a.data << endl;
        a.data = 5;
        cout << a.data << endl;
    }
};

void set_show(int x, A& a){
    a.data = x;
    cout << a.data << endl;
}

int main()
{
    class A a;
    set_show(1, a);

    class C c;
    c.set_show(a);

    system("pause");
    return 0;
}