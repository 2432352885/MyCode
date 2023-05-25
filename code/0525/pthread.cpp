#include<iostream>
#include<thread>
using namespace std;

/*
操作系统为每个进程创建巨大的 私有的虚拟内存的假象 这种地址空间的抽象让每个程序好像拥有自己的内存
实际上操作系统让多个地址空间复用 物理内存或者磁盘
        页 --->  页表  -----> 页  ------>硬盘
线程
    一个程序执行多个流程 就是多线程
    线程是调度的基本单位 进程是资源分配的基本单位
    所以线程间可以共享进程的资源 比如 代码段 堆空间 数据段 打开的文件 
    每个线程都有自己的独立的栈空间

    如果多个线程同时竞争共享资源 就会造成共享资源数据的混乱
*/

int i = 0;

//线程函数 共享变量i自增
void test()
{
    int num = 10000;

    for(int n = 0; n < num; n++)
    {
        i = i + 1;
    }
}
int main()
{
    cout << "Start all threads" << endl;

    thread thread_test1(test);
    thread thread_test2(test);//vitual stdio 上可以运行出来

    thread_test1.join();
    thread_test2.join();

    cout << i << endl;

    system("pause");
    return 0;
}