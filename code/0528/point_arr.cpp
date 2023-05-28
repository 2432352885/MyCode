#include<iostream>
using namespace std;

void func(int** p){

}
/*
运算符优先级的问题
    int arr[n]
    int (*p)[n] = &arr;  &arr表示的是数组的首地址 arr是表示首元素的地址
    ()优先级更大 行指针 
    int (*p)[n] 首先是个指针 指向一个数组 数组长度为n 也可以说是p的步长
    p+1就是跨过一个n数组的长度
    将二维数组赋值给指针
    int a[3][4];
    int(*p)[4]
    p = a;将二维数组的首地址赋值给p 是a[0]或者a[0][0]
    p++; p 跨过行a[0][]指向了a[1][0]
    数组指针只是一个指针变量 占有的内存是一个指针的存储空间
    指针数组是多个hi真变量，以数组的形式存储在内存中
    表示i行j列元素
    *(p[i] + j) *(*(p+i)+j) (*(p+i))[j] p[i][j]

    int* p[n]
    []优先级高 先和p结合成数组 之后int* 说明是个整型指针数组 n个指针类型的数组元素


    数组指针 以及i行j列数组的表示方法
*/

int main()
{
    //指针数组 指针指向数组的首地址 
    int arr[] = {1,3,2,4,5,6,7,8,9};
    int* p1 = arr;
    cout << p1 << endl;
    cout <<  "*p1  = " << (*p1) << endl;//值
    cout <<  "*p1 + 1 = " << (*p1 + 1) << " ++*p = " << ++*p1 << endl;//值变化
    cout << "*(p1 + 1) = " << *(p1 + 1) << " *(++p1) = " << *(++p1) << endl;//指针变化
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    //指针数组
    int* p[10];
    int a = 10;
    p[1] = &a;
    cout << p[1] << endl;//输出指针 地址
    cout << *p[1] << endl;//输出值

    p[2] = arr;//将首地址赋值给p2
    cout << p[2] << endl;
    cout << "*p = " << *p[2] << endl;


    //数组指针 *(p[i] + j) *(*(p+i)+j) (*(p+i))[j] p[i][j]
    int arr2[3][4] = {1,2,3,4,5,6,1,2,3,6,7,8};
    int (*p2)[4] = arr2;
    cout << "第二行 第四列" << *(p2[1]+ 3) << endl;
    cout << "第二行 第四列" << *(*(p2 + 1)+ 3) << endl;
    cout << "第二行 第四列" << (*(p2 + 1))[3] << endl;
    cout << "第二行 第四列" << p2[1][3] << endl;
    // cout << ++p2 << endl;
    // cout << "++p2之后的*p2" << *p2 << endl;

    

    
    system("pause");
    return 0;
}