#include<string>
#include<iostream>
#include<memory>
using namespace std;

int main(){
    string str = "hello";
    shared_ptr<string> ps(new(string));

    auto it1 = str.begin();
    string it2 = "";


    //当it1 == str.end()时 为空
    shared_ptr<string> ps(new string);
    while(it1 != str.end())
        it2.push_back(*it1++);
    cout << it2 << endl;



    return 0;
}