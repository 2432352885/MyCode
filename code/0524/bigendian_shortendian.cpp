/*
大端和小端
    大端存储：字数据的高字节存储在低地址中
    小端存储：字数据的低字节存储在低地址中
    在Scoket编程中 需要将操作系统所用的小端存储的IP地址转换成大端存储 这样才能网络传输
*/

#include<iostream>
using namespace std;

//union至少与容纳最大数据成员所需的一样大 通常不会更大
union endian
{
    int a;
    char ch;
};//整个union占用4字节


int main()
{   
    int a = 0x1234;
    //int 和char 的长度不同 借助int转换成char类型 指挥留下低地址部分
    char c = (char)(a);
    if(c == 0x12)
        cout << "big endian " << endl;
    if(c == 0x34)
        cout << "short endian" << endl;//输出 默认为小端存储
    
    endian value;
    value.a = 0x1234;
    //a和ch共用4字节的内存空间
    if(value.ch == 0x12)
        cout << "big endian" << endl;
    if(value.ch == 0x34)
        cout << "short endian" << endl;
    
    cout << &value.a << endl;
    cout << &value.ch << endl;


    system("pause");
    return 0;
}