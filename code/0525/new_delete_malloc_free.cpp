#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include<stdlib.h>
using namespace std;
/*
    malloc和free是标准库函数 支持覆盖
    new和delete是运算符 支持重载
    malloc仅仅分配空间 free仅仅回收空间 不具备调用构造函数和析构函数功能
    使用malloc分配空间存储类的对象存在风险
    new 和 delete除了分配和回收的功能外 还能调用析构函数
    malloc和free返回的是void类型指针 必须进行类型转换
    new 和 delete使用具体类型指针
    语法
    new data_type
    delete vriable_name

    被free回收的内存会首先被ptmalloc使用双链表保存起来 当用户下一次申请内存时 尝试从这些内存中寻找合适的
    防止频繁的系统调用 占用过多系统资源 同时ptmalloc也会尝试对小块内存进行合并 避免过多的内存碎片
*/
class A
{
public:
    A(){
        cout << "A()" << endl;
    }
    ~A(){
        cout << "~A()" << endl;
    }

};

int main()
{
    cout << "malloc分配内存" << endl;
    int* m_ptr = (int *)malloc(4);
    *m_ptr = 4;
    cout << "m_ptr = " << m_ptr << " *m_ptr = " << *m_ptr << endl;
    cout << "new分配内存" << endl;
    A* a = new A;
    cout << "a.address = " << a << endl;

    free(m_ptr);
    delete a;
    cout << m_ptr << endl;
    cout << a << endl;

    system("pause");
    return 0;
}