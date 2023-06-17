#include<iostream>  
#include<vector>
#include<cstdint>
using namespace std;


/*
    C++中四种强制类型转换介绍
        const_cast static_cast dynamic_cast reinterpret_cast

    const_cast常量指针转换成非常量指针 并且指向原来的对象
        常量引用被转换成非常量的应用 指向原来对象

    static_cast作用和C语言风格的强制转换的效果类型一样 由于没有运行时类型检查来保证转换的安全性 
        所以这类型的强制转化和C语言的强制转换都有着安全隐患

        用于类层次结构中基类和派生类之间指针或引用的转换 上行转换 子类指针或者引用转换成基类 是安全的 
        下行转换 没有动态类型检查 所以不安全

        不能转换掉原有类型的const volatie 或者__unaligned属性
        C++任何隐式转换都是使用static_cast来实现的
    
    dynamic_cast
        涉及面向对象的多态性和程序运行时的状态 也是编译器的属性设置相关 最常用 不可缺少的

    reinterpret_cast
        强制类型转换符用来处理无关类型转换 通常为操作数的为模式提供较低层次的重新解释 但是他仅仅
        重新解释了给出的对象的比特模型 没有进行二进制转换 任意指针之间 引用之间转换  指针和足够大的int
        之间转换 整数到指针的转换  
*/

class Base{
public:
    void func(){cout << "base" << endl;}
    virtual void i_am_virtual_foo() {};
};

class Sub : public Base{
public:
    void func(){
        cout << "Sub" << endl;
    }

    virtual void i_am_virtual_foo(){};
};

int main(){
    vector<int> v1{1, 2, 3, 4};
    int arr[] = {1, 2, 3, 4};
    
//cosnt_cast
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    
    //常量化数组指针
    const int* c_ptr = arr;
    //c_ptr[1] = 233;//因为是const int 类型的指针 所以不能修改值

    //通过const_cast<Ty>
    int *ptr = const_cast<int*>(c_ptr);

    for(auto i : arr)
        ptr[i] += 1;
    
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    /*
    1 2 3 4 
    1 2 3 4
    1 3 3 6
    */

   const int val = 233;//声明为常量类型
   int &use_val = const_cast<int&>(val);//使用去const引用
   int* ptr_val = const_cast<int*>(&val);//使用去const指针  const_cast 只能调节类型限定符；不能更改基础类型

   use_val = 666;
   cout << val << " " << use_val << endl;
   *ptr_val = 110;
   cout << val << " " << *ptr_val << endl;

   /*
   233 666
   233 110
   没有改变数据
   */

//static_cast
    //常规方法
    float f_pi=3.141562f;
    int i_pi = static_cast<int>(f_pi);

    cout << f_pi << " " << i_pi << endl;
    
    //上行
    // Sub sub;
    // Base *base_ptr = static_cast<Base*>(&sub);
    // base_ptr->func();//base

    //下行
    // Base base;
    // Sub* sub_ptr = static_cast<Sub*>(&base);
    // sub_ptr->func();//Sub

//dynamic_cast
    cout << "Sub->Base" << endl;
    Sub* sub = new Sub();
    sub->func();
    Base* sub2base = dynamic_cast<Base*>(sub);
    if(sub2base != nullptr)
        sub2base->func();
    
    cout << "<sub->base> sub2base val is : " << sub2base << endl;

    cout << endl << "Base->Sub" << endl;
    Base* base = new Base();
    base->func();
    Sub* base2sub = dynamic_cast<Sub*>(base);
    if(base2sub != nullptr)
        base2sub->func();
    
    cout << "<base->sub> base2sub val is " << base2sub << endl;//对此类错误的转换赋值为nullptr

    delete sub;
    delete base;
    /*
    Sub->Base
    Sub
    base
    <sub->base> sub2base val is : 0x6319f0

    Base->Sub
    base
    <base->sub> base2sub val is 0

    对于子类到基类的指针转化 dynamic_cast成功转换 并没有运行异常 达到预期效果
    从基类到子类的转换 dynamic_cast转化时没有报错 但是输出给base2sub是一个nullptr
    说明dynamic_cast在程序运行时对类型转化“运行期类型信息”进行了检查
    这个检查主要来自虚函数在C++中的面向对象的思想 虚函数起到了关键作用 当一个类中
    拥有至少一个虚函数 那么编译器就会构建出一个虚函数表来指示这些函数的地址 
    假如继承该类的子类定义并实现了一个同名并具有同样函数签名的方法重写了基类中的方法
    那么虚函数表会将该函数指向新的地址 多态性就会显示出来 当我们将基类的指针或者引用指向子类的对象时
    调用方法时 就会顺着这个虚函数表找到对应子类的方法 而不是基类的方法 
    */

//reinterpret_cast
    int* re_ptr =  new int(233);
    //error: cast from 'int*' to 'uint32_t' {aka 'unsigned int'} loses precision [-fpermissive]
    //int ptr_addr = reinterpret_cast<int>(re_ptr);
    cout << "ptr地址 " << hex << ptr << endl;
        //<< "ptr_addr的值：" << hex << ptr_addr << endl;
    delete ptr;

    return 0;
}