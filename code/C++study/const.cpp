//const������ѧϰ
#include <iostream>
using namespace std;
#include<string>
#include"constfile.cpp"

//���� const����
extern const int ext;

/*
    ������ʹ��const
        const int fun1();������
        const int* fun();ָ��ָ������ݲ��ɱ�
        int *const fun();ָ�뱾���ɱ�
        void func(const A &a) ����Ϊ���� ����Ч�ʷ�ֹ�޸�
*/

//�����Ĳ���ʹ��const���� ��ֹ�޸����� �𵽱��������� ��ǿ����Ľ�׳��
//��������
const void swap(const int &a, const int &b);

/*
    const���峣���ӻ��ĽǶ����� 
    ֻ�Ǹ���һ����Ӧ���ڴ��ַ ��������defineһ������������
    const������������ #define�궨����û���������� ֻ�Ǽ򵥵��ַ����滻
    const����ĳ����ڳ������е�ʱ��ֻ��һ�ݿ��� ����#define����ĳ����Ӱ��ڴ�����
    ���ɸ����� -----�������Խ�ʡ�ռ� ���ⲻ��Ҫ���ڴ���� ���������ܹ����а�ȫ���
    �����ͼ�顣
*/



int main()
{
/*
    const����� ��������ɲ����޸ĵ���ֵ��
*/

//const�����
    //const ����ֵ��ɲ����޸ĵ���ֵ ����һ��const�޶��ı��������ǳ���
    const int a = 10;
    const int b = 20;
    int c = 20;
    const string s = "hello i am xx";
    //���������ʼ��
    //const int i;


/*
    const��ָ��С�᣺
        const λ��*����� ��������ָ����ָ��ı��� �൱�ڽ�ָ������� �̶�������ֵ
        constλ��*�Ҳ� ����ָ�� ָ����ָ�ĵ�ַ���ı� ����ֵ���Ըı�
        ����ָ������ָ�� ����ͨ��ָ�����޸Ķ����ֵ
        ����ʹ��void *ָ��������const����ĵ�ַ ����ʹ��const void *
        ��const����ĵ�ַ���Ը�ֵ��const�����ָ��
*/

//const��ָ��
    //ָ��const�����ָ�� ָ������ָ�� ��ֵ���ܸı�
    const int *p;
    //ָ�����Ͷ���constָ�� ��Ҫ��ʼ�� ��ָ�� constָ�� ����ָ��const���� c���Ա仯 ���ǵ�ַ����
    //��ָ��
    int* const p2 = &c;
    cout << "*p2 = " << *p2 << " c = "  << c << endl;//20 20

    *p2 = 30;
    cout << "*p2 = " << *p2 << " c = "  << c << endl;//30 30

    p = &a;
    //p2 = &b;error ��ַ�Ѿ�ȷ�������޸� ���������ơ�
    const int *ptr;
    //*ptr = 20; error�����Ǳ��� ���Ҳ����޸ı�����ֵ��
    const void *vptr = &a;
    //void *vptr1 = &a;����ָ�������Ķ������͵�ָ�� ����ʹ��void *����ָ�뱣��const����ĵ�ַ ������const void*���Ͳſ���

    //��ַ
    cout << "a�ĵ�ַΪ��" << &a << endl;//0x61fdf0
    cout << "pΪ��" << p << endl;//0x61fdf0
    //ֵ
    cout <<"*p = " << *p << endl;//10
    //��ַ
    cout <<"p2 = " << p2 << endl;//0x61fdec
    cout << "c.address: " <<  &c << endl;//0x61fdec
    //ֵ
    cout << "*p2 = " << *p2 << endl;//20

    cout << "s.len = " <<s.size() << endl;//���s�Ĵ�С 13
    //swap(a, b);

    //����const����ֵ��const����ָ�� ����ͨ��ptrָ�����޸�val��ֵ
    const int *ptr2;
    int val = 10;
    ptr2 = &val;

//const����һ���ļ���������� 
    Math math;
    //ͨ�������õ�const����
    cout << math.c << endl;//10
    //ͨ���������õ���һ���ļ����������
    cout << (ext + 10) << endl;//11



    system("pause");
    return 0;
}