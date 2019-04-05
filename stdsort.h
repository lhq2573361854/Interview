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
    int* selectSort();
    int* bulletSort();
    int* insertSort();
    int* quickSort();
    int* mergeSort();
    int* heapSort();
    int getWidth();
    void print();
    void setWidth(int n);
    int *_getRandom();
    int* getArr();
    void setArr(int *arr);
};

int Sort::getWidth(){
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
int* Sort::insertSort() {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j-1] ; --j) {
            swap(arr[j],arr[j-1]);
        }
    }
}
void Sort::print() {
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}
#endif //INDEX2_STDSORT_H
