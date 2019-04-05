#include<bits/stdc++.h>
#include"stdsort.h"
#include <windows.h>
using namespace std;



int main(){
    Sort* sort = new Sort(10000);
    sort->setArr(sort->_getRandom());
  //  sort->print();
    double start,end;
    start = clock();
    sort->quickSort();
    end = clock();
    cout << end -start<<endl;
    //sort->print();
    return 0;
}