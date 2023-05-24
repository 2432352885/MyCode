#include"command.h"

//求Π 可以使用格雷戈里-莱布尼兹无穷级数来求
//(4/1)-(4/3) + (4/5) - (4/7) ...
void compute(double &x)
{
    double a = 1.0;
    while(a <= 1000000.0)//3.14159
    {
        x += ((4.0/a) - (4.0/(a+2)));
        a += 4.0;
    }
}
//
int main()
{
    double x = 0.00000;
    compute(x);
    

    cout << x << endl;
    system("pause");
    return 0;
}