#include<bits/stdc++.h>
#include"stdsort.h"
#include <windows.h>
using namespace std;
int main(){
    Sort* sort = new Sort(100);
    sort->_getRandom();
    sort->print();
    double start = clock();
    sort->insertSort();
    double end = clock();
    cout << end-start <<endl;
    sort->print();
    return 0;
}

