#include<iostream>
#include<type_traits>
using namespace std;

void foo(char *);
void foo(int);

int main(){
    //is_same比较两个类型是否相同 decltype用于类型推导
    if(is_same<decltype(NULL), decltype(0)>::value)
        cout << "NULL == 0" << endl;
    if(is_same<decltype(NULL), decltype((void *)0)>::value)
        cout << "NULL == (void*)0" << endl;
    if(is_same<decltype(NULL), nullptr_t>::value)
        cout << "NULL == nullptr" << endl;

    foo(0);//this is int function
    foo(nullptr);//this is char* function
    //可以知道nullptr和NULL和0是不同的
    system("pause");
    return 0;
}

void foo(char *){
    cout << "this is char* function" << endl;
}

void foo(int i){
    cout << "this is int function" << endl;
}