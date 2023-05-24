#include"command.h"

//联合体学习
class Union{
public:
    class b{
    public:
        int x;
        int y;
        int z;
    } u;

    int k;
} a;

int main()
{
    //将类中的类赋值
    a.u.x = 1;
    a.u.y = 2;
    a.u.z = 3;
    //如果k是私有的话需要通过构造函数去赋值。
    a.k = 10;


    system("pause");
    return 0;
    
}