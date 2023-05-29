/*
    No.1 异常处理机制
        A函数发现问题 不做处理 抛出异常 放到A的调用者B函数中处理
        问题的延期处理
    No.2 异常处理的关键字
        throw 抛出异常
        try 捕获异常
        catch 处理异常
    No.3 注意
        try and catch必须一起使用 大括号不能省略
        当抛出异常 不做处理时 调用abort终止程序
    No.4 删减符 ...
        任何东西都可以捕获 无法获取异常类型
    No.5 不存在异常的描述 throw()和noexpect
        通过noexcept修饰函数 偏要抛出异常 就会引发

*/

#include<iostream>
using namespace std;

int divisor(int a, int b){
    if(b == 0)
        throw b; //抛出B 不能对
    cout << "子程序" << endl;
    return (a / b);
}

void testDeleteOperator(){
    try{
        divisor(1, 0);
    }
    catch(...){
        cout << "任何抛出的异常" << endl;
    }
}

int Min(int a, int b) throw(){
    return a > b ? b : a;
}

int Max(int a, int b) noexcept{
    return a > b ? a : b;
}

int transferParameters(){
    try{
        divisor(1, 0);
        cout << "这里不会执行" << endl;
    }
    catch(int num){
        cout << "num = " << num << endl;
        cout << "除数不能为0" << endl;
    }
}

int main(){

    try{//一个try对应多个catch 但是只能执行一个catch
        divisor(20, 0);
    }
    catch(int) //根据抛出的数据类型决定如何处理异常
    {
        cout << "除数不能为0" << endl;
    }
    
    cout << divisor(20, 10) << endl;

    testDeleteOperator();

    transferParameters();

    system("pause");
    return 0;
}