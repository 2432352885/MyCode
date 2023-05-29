#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;


int main()
{
	int a = -1;
	//int* p = new double[a];
	string* p1 = new string[a];
	//int* p3 = "380";
	cout << p1[1] << endl;
	delete[] p1;

	return 0;
}