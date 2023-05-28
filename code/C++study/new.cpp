/*
new的三种典型使用方法
plain new 普通的new 在空间分配失败 抛出异常std::bad_alloc不是返回NULL
nothrow new 
placement new
*/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    try
    {
        double a = 10e11;
        char* p = new char[int(a)];
        delete p;
    }
    catch(const std::bad_alloc &ex)
    {
        cout << ex.what() << endl;//std::bad_alloc
    }

    system("pause");
    return 0;
}