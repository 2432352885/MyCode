#include "command.h"

//判断是否为闰年
//闰年就是366天的那年 每四年一个闰年
//润年就是4的倍数 但是不是100的倍数
int main()
{
    int year = 0;
    cout << "请输入需要查询的年份：" << endl;
    cin >> year;

    //判断该年份是否为闰年 400的倍数和4的倍数但不是100的倍数
    if(year > 0)
    {
        if(year % 400 == 0)
        {
            cout << "该年是闰年" << endl;
        }
        else if((year % 4 == 0) && (year % 100 != 0))
        {
            cout << "该年为闰年" << endl;
        }
        else {
            cout << "不是闰年" << endl;
        }
    }

    cout << "输入错误" << endl;

    system("pause");
    return 0;
}