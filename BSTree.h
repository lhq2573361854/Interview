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
    int height=1;
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
    void _preOrder(TreeNode* node);
    void _inOrder(TreeNode* node);
    void _postOrder(TreeNode* node);
    void _preOrderNR(TreeNode* node);
    void _inOrderNR(TreeNode* node);
    void _postOrderNR(TreeNode* node);
    int _getHeight(TreeNode* node);
    void _LevelTraverse(TreeNode* node);
    void _PrintNodeAtLevel(TreeNode*,int);
    void _levelTraverseNR(TreeNode* node);
public:
    void inOrder();
    void preOrder();
    void postOrder();
    void inOrderNR();
    void preOrderNR();
    void postOrderNR();
    int getHeight();
    TreeNode* createTree(int*, int);
    void LevelTraverse();
    void LevelTraverseNR();
};

//========================PUBLIC================================
void BSTree::preOrder() {
    _preOrder(root);
}
void BSTree::inOrder() {
    _inOrder(root);
}
void BSTree::postOrder() {
    _postOrder(root);
}

void BSTree::preOrderNR() {
    _preOrderNR(root);
}
void BSTree::inOrderNR() {
    _inOrderNR(root);
}
void BSTree::postOrderNR() {
    _postOrderNR(root);
}
TreeNode* BSTree::createTree(int* arr, int n) {
    _createTree(arr,n);
}
int BSTree::getHeight() {
    return _getHeight(root);
}

void BSTree::LevelTraverse(){
    _LevelTraverse(root);
}
void BSTree::LevelTraverseNR(){
    _levelTraverseNR(root);
}
//========================PUBLIC================================


//========================PRIVATE===============================
/**
 *
 * @param arr 数组
 * @param n   数组大小
 * @return    返回值为根节点
 * 创建一个BST树
 */
TreeNode* BSTree::_createTree(int* arr, int n){
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = _add_Element(root,arr[i]);
    }
    return root;
}
/**
 * @param root 根节点
 * @param val  节点的值
 * @return      返回根节点
 *  向BST添加一个元素
 */
TreeNode* BSTree::_add_Element(TreeNode *root, int val) {
    if(root == NULL)
        return new TreeNode(val);
    if(val < root->val)
        root->left = _add_Element(root->left, val);
    else if(val > root->val)
        root->right = _add_Element(root->right, val);

    root->height = max(_getHeight(root->left),_getHeight(root->right))+1;
    return root;

}

/**
 * @param node 根节点
 * 前序遍历以node为根的二分搜索树, 递归算法
 */
void BSTree::_preOrder(TreeNode* node){

    if(node == NULL)
        return;
    cout << node->val<<" " ;
    _preOrder(node->left);
    _preOrder(node->right);
}

/**
 *
 * @param node 根节点
 * 前序遍历以node为根的二分搜索树, 非递归算法
 */

void BSTree::_preOrderNR(TreeNode* node){
    stack<TreeNode*> s1;
    s1.push(node);
    while(!s1.empty()){
        TreeNode* temp = s1.top();
        s1.pop();
        cout << temp->val<<" ";
        if(temp->right!=NULL) s1.push(temp->right);
        if(temp->left!=NULL) s1.push(temp->left);
    }
}

/**
 * @param node
 * 中遍历以node为根的二分搜索树, 递归算法
 */
void BSTree::_inOrder(TreeNode* node){

    if(node == NULL)
        return;
    _inOrder(node->left);
    cout << node->val<<" " ;
    _inOrder(node->right);
}
/**
 * @param node
 * 中遍历以node为根的二分搜索树, 非递归算法
 */

void BSTree::_inOrderNR(TreeNode* node){
    stack<TreeNode*> s1;
    while(!s1.empty() ||  node!= NULL){
        if(node != NULL){
            s1.push(node);
            node = node->left;
        }else{
            node = s1.top();
            s1.pop();
            cout<< node->val << " ";
            node = node->right;
        }
    }
}
/**
 * @param node
 * 后序遍历以node为根的二分搜索树, 递归算法
 */
void BSTree::_postOrder(TreeNode* node){

    if(node == NULL)
        return;
    _postOrder(node->left);
    _postOrder(node->right);
    cout << node->val<<" " ;
}
/**
 *
 * @param node 根节点
 * 后序遍历以node为根的二分搜索树, 非递归算法
 */
void BSTree::_postOrderNR(TreeNode* node){
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(node);
    while(!s1.empty()){
      TreeNode* temp = s1.top();
      s1.pop();
      s2.push(temp);
      if(temp->left != NULL)  s1.push(temp->left);
      if(temp->right!= NULL)  s1.push(temp->right);
    }

    while(!s2.empty()){
       TreeNode* temp =  s2.top();
       s2.pop();
       cout << temp->val << " ";
    }
}
/**
 *
 * @param node 某一个节点
 * @return     返回一个节点的高度
 */
int BSTree::_getHeight(TreeNode *node) {
    if(node!=NULL)
        return node->height;
    return 0;
}
/**
 *
 * @param T     根节点
 * @param level 层数
 *
 * 层次遍历主函数
 */
void BSTree::_PrintNodeAtLevel(TreeNode* T,int level){
    if (NULL == T || level < 1 )
        return;
    if (1 == level){
        cout << T->val << " ";
        return;
    }
    // 左子树的 level - 1 级
    _PrintNodeAtLevel(T->left,  level - 1);

    // 右子树的 level - 1 级
    _PrintNodeAtLevel(T->right, level - 1);
}

/**
 * @param node 根节点
 *  层次遍历以node为根的二分搜索树, 递归算法
 */
void BSTree::_LevelTraverse( TreeNode* node){
    if (NULL == node)
        return;
    int depth = getHeight();
    int i;
    for (i = 1; i <= depth; i++){
        _PrintNodeAtLevel(node, i);
    }
}

void BSTree::_levelTraverseNR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        cout << node->val << " ";
        if (node->left != NULL) {
            queue.push(node->left);
        }
        if (node->right != NULL) {
            queue.push(node->right);
        }
    }
}
//========================PRIVATE===============================
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


#endif //FIRST_BST_H
