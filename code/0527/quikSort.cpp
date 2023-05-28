#include<iostream>
#include<random>
#include<time.h>
#include<stdlib.h>
using namespace std;

/*
快排
    从数组中随机选一个数 放到最后位置 
    srand((unsigned int)(time (NULL)))
    取[a,b) (rand()%(b - a)) + a
    取[a,b] (rand()%(b - a + 1)) + a
    取(a,b] (rand()%(b - a)) + a + 1
    将小于这个数的放左边 大于这个数的放右边
    之后在左侧和右侧也分别做patition操作
    知道整体有序
*/
//交换数
void swap(int arr[],int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

//返回左边界和又边界
int* patition(int arr[], int L, int R){
    int less = L - 1; //<区右边界
    int more = R;//>区左边界 
    while(L < more){
        if(arr[L] < arr[R]){
            swap(arr, ++less, L++);
        }else if(arr[L] > arr[R]){
            swap(arr, --more, L);
        }else{
            L++;
        }
    }
    swap(arr, more, R);
    
    return new int[2]{less + 1, more};//返回临时对象
}

void QuickSort(int arr[], int L, int R){
    srand((unsigned) time(NULL));//随机种子
    if(L < R){
        unsigned int num = (rand() % (R - L + 1)) + L;//从L到R上随机选一个数
        swap(arr, R, num);
        int* tmp = patition(arr, L, R);//返回一个数组 并且长度为二
        QuickSort(arr, L, tmp[0] - 1);// < 区
        QuickSort(arr, tmp[1] + 1, R);// > 区
        delete[] tmp;
    }

}
int main()
{
    int arr[] = {1, 3, 3, 2, 2, 5, 4, 6, 4, 9, 1, 7, 8};
    QuickSort(arr, 0, 12);

    for(auto i : arr){
        cout << i << " ";
    }

    cout << endl;


    system("pause");
    return 0;
}