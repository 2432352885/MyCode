/*
    并行编程
        计算密集 大量数据并行处理
        任务并行 游戏中的不同线程处理不同任务
    难点
        同步
        调试困难 死锁、饥饿
        IO

    Process VS Thread
        当kill一些thread时 不会释放资源

    找数组中的最大值
        给定无序数组 百万级
        写多线程时是需要同步的

    CPU
        cache 在多线程时不能忽视 分成三级cache L1 L2 L3

    volatile
        当对变量进行读和写都会到内存里面
*/

#include<thread>
#include<iostream>
using namespace std;

int count = 0;

void AddTest(){
    for(int i = 0; i < 100000; i++)
        count++;
}

int main(){
    //thread(AddTest);



    system("pause");
    return 0;
}