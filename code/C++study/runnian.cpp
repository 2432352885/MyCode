#include "command.h"

//�ж��Ƿ�Ϊ����
//�������366������� ÿ����һ������
//�������4�ı��� ���ǲ���100�ı���
int main()
{
    int year = 0;
    cout << "��������Ҫ��ѯ����ݣ�" << endl;
    cin >> year;

    //�жϸ�����Ƿ�Ϊ���� 400�ı�����4�ı���������100�ı���
    if(year > 0)
    {
        if(year % 400 == 0)
        {
            cout << "����������" << endl;
        }
        else if((year % 4 == 0) && (year % 100 != 0))
        {
            cout << "����Ϊ����" << endl;
        }
        else {
            cout << "��������" << endl;
        }
    }

    cout << "�������" << endl;

    system("pause");
    return 0;
}