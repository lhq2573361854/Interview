#include<bits/stdc++.h>
#include"stdsort.h"
#include <windows.h>
#include "BSTree.h"
using namespace std;
int main(){
    int n =10;
    int* arr = _getRandomArr(n);
    print(arr,n);
    BSTree* bt = new BSTree(arr,n);
    bt->LevelTraverse();
    cout << endl;
    bt->LevelTraverseNR();
    return 0;
}

