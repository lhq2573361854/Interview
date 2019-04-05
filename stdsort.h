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
    int count;
    int* data;
    Sort(){
    }
    Sort(int n){
        this->n = n;
        this->count = n;
        data = new int[n+1];
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
    void _siftup(int index);
    void _siftDown(int index);
    void _parent(int index);
    void _left(int index);
    void _right( int index);
    int extractMax();
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
    for (int i = 0; i < n; ++i){
        arr[i]= rand()%n;
        data[i+1] = arr[i];
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
    srand(time(NULL));
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
void Sort::_siftup(int index) {
    while(index > 1 && data[index/2] < data[index] ){
        swap( data[index/2], data[index] );
        index/=2;
    }
}
void Sort::_siftDown(int index) {
    while(2*index <= count ){
        int j = 2* index;
        if(j+1 <= count && data[j+1]> data[j])
            j++;
        if(data[j] <= data[index] ) break;
        swap( data[index] , data[j] );
        index = j;
    }
}
int Sort::extractMax(){
    assert( count > 0 );
    int ret = data[1];
    swap( data[1] , data[count] );
    count--;
    _siftDown(1);
    return ret;
}
void Sort::heapSort() {
    for( int i = count/2 ; i >= 1 ; i -- )
        _siftDown(i);

    for( int i = n-1 ; i >= 0 ; i-- ){
        arr[i] = extractMax();
    }
}


void Sort::print() {
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}
#endif //INDEX2_STDSORT_H
