#include<iostream>
using namespace std;

class A{
public:
    int id;
    A() : id(0){
        cout << "default ctor.this = " << this << " id = " << id <<endl;  
    }
    A(int i) : id(i) {
        cout << "ctor.this = " << this << " id = " << id << endl;
    }
    ~A(){ 
        cout << "dtor.this = " << this << "id = " << id << endl; 
    }
};

int main()
{
    int size = 3;

    // default ctor.this = 0x1061838 id = 0
    // default ctor.this = 0x106183c id = 0
    // default ctor.this = 0x1061840 id = 0
    A* buf = new A[size];//! 类 "A" 不存在默认构造函数

    A* tmp = buf;
    //buf = 0xe41838 tmp = 0xe41838
    cout << "buf = " << buf << " tmp = " << tmp << endl;

    for(int i = 0; i < size; i++)
        new(tmp++)A(i);//在tmp这个位置上建立一个东西
    // ctor.this = 0xe41838 id = 0
    // ctor.this = 0xe4183c id = 1
    // ctor.this = 0xe41840 id = 2
    
    //buf = 0xe41838 tmp = 0xe41844
    cout << "buf = " << buf << "tmp = " << tmp << endl;

// dtor.this = 0xe41840 id = 2
// dtor.this = 0xe4183c id = 1
// dtor.this = 0xe41838 id = 0
    delete[] buf;//构建是从上往下 析构是从下往上

    system("pause");
    return 0;
}