#include <iostream>

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r) {
    // v是 arr[l]
    //partition arr 使得arr[l + 1, j] < v 使得 arr[j+1, i) >= v
    int j = l;
    for(int i = l + 1; i <= r; i++) {
        if(arr[i] < arr[l]) {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
    if(l >= r) {
        return;
    }
    int mid = __partition(arr, l, r);
    __quickSort(arr, l, mid - 1);
    __quickSort(arr, mid + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n - 1);
}