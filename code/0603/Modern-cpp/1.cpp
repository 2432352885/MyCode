#include"foo.h"
#include<iostream>
#include<functional>
using namespace std;

int main(){
    [out = ref(cout << "Result from C code: " << add(1, 2))](){
        out.get() << ".\n";
    }();

    system("pause");
    return 0;
}