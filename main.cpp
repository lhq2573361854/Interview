#include<bits/stdc++.h>
#include"stdsort.h"
using namespace std;
int main(){
    Sort* sort = new Sort();
    sort->setWidth(10);
    sort->setArr(sort->_getRandom());
    sort->print();
    sort->insertSort();
    sort->print();
    cout <<"12312"<<endl;
    return 0;
}