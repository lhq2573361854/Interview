//
// Created by HuanLing on 2019/4/11.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef FIRST_BST_H
#define FIRST_BST_H
typedef struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
    treenode(){};
    treenode(int val): val(val),left(NULL),right(NULL){};
}TreeNode;

class BSTree{
public:
    BSTree(){
        root =NULL;
    }
    BSTree(int* arr,int n){
        root = _createTree(arr,n);
    }
private:
    TreeNode* root;
    TreeNode* _createTree(int*, int );
    TreeNode* _add_Element(TreeNode* ,int);
    void _inOrder(TreeNode* node);
public:
    void inOrder();
    TreeNode* createTree(int*, int);

};

//========================PUBLIC================================
void BSTree::inOrder() {
    _inOrder(root);
}
TreeNode* BSTree::createTree(int* arr, int n) {
    _createTree(arr,n);
}
//========================PUBLIC================================


//========================PRIVATE===============================
//创建一个BST树
TreeNode* BSTree::_createTree(int* arr, int n){
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = _add_Element(root,arr[i]);
    }
    return root;
}
//添加一个元素
TreeNode* BSTree::_add_Element(TreeNode *root, int val) {
    if(root == NULL)
        return new TreeNode(val);
    if(val < root->val)
        root->left = _add_Element(root->left, val);
    else if(val > root->val)
        root->right = _add_Element(root->right, val);
    return root;

}
//中序遍历以node为根的二分搜索树, 递归算法
void BSTree::_inOrder(TreeNode* node){

    if(node == NULL)
        return;
    _inOrder(node->left);
    cout << node->val<<" " ;
    _inOrder(node->right);
}
//获取随机数组
int*  _getRandomArr(int n){
    int* arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        arr[i]= rand()%n;
    }
    return arr;
}
//打印数组
void print(int* arr,int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i]<< " ";
    }
    cout << endl;
}
//========================PRIVATE===============================



#endif //FIRST_BST_H
