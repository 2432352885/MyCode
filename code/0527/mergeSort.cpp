#include<iostream>
using namespace std;
/*
    归并排序
        mergeSort()
        首先将数组分成两部分 通过递归的方法 就数组分开
        在和合并
        如果左侧小于右侧 将左侧放到辅助空间
        如果越界 将剩下的全部放入之后
*/
//左侧有序 右侧也有序 合并之后整体有序
void merge(int arr[], int left, int right, int mid){
    int len = right - left + 1;
    int i = 0;
    int* tmp = new int[len];
    int p1 = left;
    int p2 = mid + 1;
    //都不越界的情况下 将两边的数进行比较
    while(p1 <= mid && p2 <= right){
        tmp[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    //p2越界之后 就是将p1的数全部拷贝
    while(p1 <= mid){
        tmp[i++] = arr[p1++];
    }
    while(p2 <= right){
        tmp[i++] = arr[p2++];
    }
    //将创建的数组放入原数组
    for(i = 0; i < len; i++){

        arr[left + i] = tmp[i];//细节注意
    }
    delete[] tmp;
}

void mergeSort(int arr[], int left, int right){
    if(left == right){
       return;
    }
    int mid = ((right - left )/2) + left;
    mergeSort(arr, left, mid);//左侧有序
    mergeSort(arr, mid + 1, right);//右侧有序
    merge(arr, left, right, mid);//合并
   
}


int main()
{
    int arr[] = {1, 5, 7, 3, 2, 9, 8};
    mergeSort(arr, 0, 6);

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}