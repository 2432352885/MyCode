//const常量的学习
#include <iostream>
using namespace std;
#include<string>
#include"constfile.cpp"

//声明 const变量
extern const int ext;

/*
    函数中使用const
        const int fun1();无意义
        const int* fun();指针指向的内容不可变
        int *const fun();指针本身不可变
        void func(const A &a) 参数为引用 增加效率防止修改
*/

//函数的参数使用const修饰 防止修改数据 起到保护的作用 增强程序的健壮性
//函数声明
const void swap(const int &a, const int &b);

/*
    const定义常量从汇编的角度来看 
    只是给出一个对应的内存地址 而不是像define一样给出立即数
    const常量具有类型 #define宏定义是没有数据类型 只是简单的字符串替换
    const定义的常量在程序运行的时候只有一份拷贝 但是#define定义的常量子啊内存中是
    若干个拷贝 -----这样可以节省空间 避免不必要的内存分配 编译器还能够进行安全检查
    即类型检查。
*/



int main()
{
/*
    const与变量 将变量变成不可修改的左值。
*/

//const与变量
    //const 将数值变成不可修改的左值 还是一个const限定的变量而不是常量
    const int a = 10;
    const int b = 20;
    int c = 20;
    const string s = "hello i am xx";
    //常量必须初始化
    //const int i;


/*
    const与指针小结：
        const 位于*的左侧 代表修饰指针所指向的变量 相当于将指针解引用 固定变量的值
        const位于*右侧 修饰指针 指针所指的地址不改变 但是值可以改变
        对于指向常量的指针 不能通过指针来修改对象的值
        不能使用void *指针来保存const对象的地址 可以使用const void *
        非const对象的地址可以赋值给const对象的指针
*/

//const与指针
    //指向const对象的指针 指向常量的指针 数值不能改变
    const int *p;
    //指向类型对象const指针 需要初始化 常指针 const指针 不能指向const常量 c可以变化 但是地址不变
    //常指针
    int* const p2 = &c;
    cout << "*p2 = " << *p2 << " c = "  << c << endl;//20 20

    *p2 = 30;
    cout << "*p2 = " << *p2 << " c = "  << c << endl;//30 30

    p = &a;
    //p2 = &b;error 地址已经确定不可修改 和引用类似。
    const int *ptr;
    //*ptr = 20; error必须是变量 并且不可修改变量的值。
    const void *vptr = &a;
    //void *vptr1 = &a;必须指向完整的对象类型的指针 不能使用void *类型指针保存const对象的地址 必须是const void*类型才可以

    //地址
    cout << "a的地址为：" << &a << endl;//0x61fdf0
    cout << "p为：" << p << endl;//0x61fdf0
    //值
    cout <<"*p = " << *p << endl;//10
    //地址
    cout <<"p2 = " << p2 << endl;//0x61fdec
    cout << "c.address: " <<  &c << endl;//0x61fdec
    //值
    cout << "*p2 = " << *p2 << endl;//20

    cout << "s.len = " <<s.size() << endl;//输出s的大小 13
    //swap(a, b);

    //将非const对象赋值给const对象指针 不能通过ptr指针来修改val的值
    const int *ptr2;
    int val = 10;
    ptr2 = &val;

//const与另一个文件定义的数据 
    Math math;
    //通过类来拿到const数据
    cout << math.c << endl;//10
    //通过声明来拿到另一个文件里面的数据
    cout << (ext + 10) << endl;//11



    system("pause");
    return 0;
}