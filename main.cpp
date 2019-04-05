#include<bits/stdc++.h>
#include"stdsort.h"
#include <windows.h>
using namespace std;
int main(){
    Sort* sort = new Sort();
    sort->setWidth(2000);
    sort->setArr(sort->_getRandom());
    sort->print();
    sort->quickSort();
    sort->print();
    return 0;
}