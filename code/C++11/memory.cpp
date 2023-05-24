#include<iostream>
using namespace std;

class Person
{
public:
    int age;

    Person(){
        this->age = 23;
    }

    void showAge(){
        cout << this->age << endl;
    }

    ~Person(){};
};

int main()
{
    Person p;
    cout << "p的地址：" << (&p) << endl;
    cout << "age的地址：" << (&p.age) << endl;
    cout << "p的大小：" << sizeof(p) << endl;
    cout << "age的大小：" << sizeof(p.age) << endl;

    system("pause");
    return 0;
   
}