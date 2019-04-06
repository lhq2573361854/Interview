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
	//选择排序
    void  selectSort();
    //冒泡排序
	void bulletSort();
    //插入排序
	void insertSort();
	//希尔排序
    void shellSort();
	//三路快排
    void  quickSort();
    void  _quickSort(int l , int r,int* arr);
	//归并排序
    void mergeSort();
    void mergeSort(int l, int r);
    void _mergeSort(int* arr,int l,int mid, int r);
    void mergeSortBU();
	//堆排序
    void heapSort();
    void _siftup(int index);
    void _siftDown(int index);
    int extractMax();

    int maxbit();
    void radixsort();

	//相当于javaBean
    int getWidth();
    void setWidth(int n);
    void _getRandom();
    int* getArr();
    void setArr(int *arr);
	//toString方法
	void print();
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
void  Sort::_getRandom(){
    arr =new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        arr[i]= rand()%n;
        data[i+1] = arr[i];
    }

}
void Sort::insertSort() {
    for( int i = 1 ; i < n ; i ++ ){
        int  e = arr[i];
        int j;
        for( j = i ; j > 0 && e < arr[j-1] ; j-- )
            arr[j] = arr[j-1];
        arr[j] = e;
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
void Sort::shellSort(){
    int h = 1;
    while(3*h < n) h = h*3+1;
    while(h >= 1){
        for( int i = h ; i < n ; i ++ ){
            int  e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h /= 3;
    }
}

void Sort::quickSort(){
    srand(time(NULL));
    _quickSort(0,n-1,arr);
}
void Sort::_quickSort(int l , int r,int* arr){
    if(l >= r)
        return ;
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
    for (int k = l; k <= r; ++k) {
        if(i > mid){
            arr[k]=aux[j-l];
            j++;
        }else if(j > r){
            arr[k] = aux[i-l];
            i ++;
        }else if(aux[i-l] < aux[j-l] ){
            arr[k]=aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }

}

void Sort::mergeSortBU(){
    for (int sz = 1; sz <= n; sz += sz){
        for (int i = 0; i + sz < n; i += sz + sz ){
            _mergeSort(arr, i, i + sz - 1, min(i + sz + sz -1, n - 1));
        }
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

int Sort::maxbit()
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(arr[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void Sort::radixsort(){
    int d = maxbit();
    int tmp[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++) {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (arr[j] / radix) % 10;
            tmp[count[k] - 1] = arr[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            arr[j] = tmp[j];
        radix = radix * 10;
    }

}

void Sort::print() {
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}



#endif //INDEX2_STDSORT_H
