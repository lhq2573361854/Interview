//
// Created by Administrator on 2019/4/5.
//

#ifndef INDEX2_STDSORT_H
#define INDEX2_STDSORT_H

#include <bits/stdc++.h>
using namespace std;
class Sort
{
private:
    int* arr;
    int n;
public:
    Sort(){

    }
    void  selectSort();
    void bulletSort();
    void insertSort();
    void  quickSort();
    void  _quickSort(int l , int r,int* arr);
    void mergeSort();
    void mergeSort(int l, int r);
    void _mergeSort(int* arr,int l,int mid, int r);
    void heapSort();
    int getWidth();
    void print();
    void setWidth(int n);
    int *_getRandom();
    int* getArr();
    void setArr(int *arr);
};

int  Sort::getWidth(){
    return n ;
}
void Sort::setWidth( int n ){
    this->n = n;
}
int* Sort::getArr(){
    return arr ;
}
void Sort::setArr( int* arr ){
    this->arr = arr;
}
int* Sort::_getRandom(){
    int* arr =new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i]= rand()%n;
    }
    return arr;
}
void Sort::insertSort() {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j-1] ; --j) {
            swap(arr[j],arr[j-1]);
        }
    }
}
void Sort::selectSort() {
    for (int i = 0; i < n; ++i) {
        int temp = i;
        for (int j = i+1; j < n ; j++) {
            if(arr[temp] > arr[j])
                temp = j;
        }
        swap(arr[i],arr[temp]);
    }
}
void Sort::bulletSort() {
    for (int i = 0; i < n; ++i){
        int temp = i;
        for (int j = i; j < n ; j++) {
            temp = arr[temp] > arr[j]? j : temp;
        }
        swap(arr[i],arr[temp]);
    }
}
void Sort::quickSort(){
    _quickSort(0,n-1,arr);
}
void Sort::_quickSort(int l , int r,int* arr){
    if(r -l <= 15){
        insertSort();
        return ;
    }
    swap( arr[l], arr[rand()%(r-l+1)+l ] );
    int lt = l;
    int gt = r+1;
    int i = l+1;
    int val = arr[l];
    while(i < gt){
        if(arr[i] < val)
            swap(arr[i++],arr[++lt]);
        else if(arr[i] > val)
            swap(arr[i],arr[--gt]);
        else
            i++;
    }
    swap(arr[lt],arr[l]);

    _quickSort(l,lt-1,arr);
    _quickSort(gt,r,arr);
}
void Sort::mergeSort(){
    mergeSort(0,n-1);
}
void Sort::mergeSort( int l, int r) {
    // 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertSort();
        return;
    }
    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    if( arr[mid] > arr[mid+1] )
        _mergeSort(arr, l, mid, r);
}
void Sort::_mergeSort(int* arr,int l, int mid, int r) {
    int* aux = new int[r-l+1];
    for (int i = l; i <=r; ++i)
        aux[i-l] = arr[i];
    int i = l;
    int j = mid+1;
    for (int k = 0; k <= r; ++k) {
     if(i > j)
         arr[k]=aux[j++];
     else if(j > r)
         arr[k]= aux[i++];
     if(aux[i] < aux[j] )
         arr[k]=aux[i++];
     else if(aux[i] < aux[j])
         arr[k] = aux[j++];
    }

}
void Sort::print() {
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}
#endif //INDEX2_STDSORT_H
