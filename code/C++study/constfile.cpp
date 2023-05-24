#include<iostream>
using namespace std;

class Math{
public:
    const int c = 10;
    int d = 30;
};

/*
    const对象默认为文件局部变量
    没有显式的指出就不能调用 extern
*/
extern const int ext = 1;

