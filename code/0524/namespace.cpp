#include<iostream>

namespace A{
    int a = 100;
    namespace B{
        int a = 20;
    }
}

int a = 1000;

int main()
{
    std::cout << "不使用using namespace std时，使用std需要加上作用域" << std::endl;

    std::cout << A::a << std::endl;
    std::cout << A::B::a << std::endl;

    std::cout << a << std::endl;

    using namespace A;
    using namespace std;
    using namespace A::B;

    //cout << a << endl;//不明确的a 当时相同变量名的变量需要在前面增加作用域来区分变量

    system("pause");
    return 0;
}