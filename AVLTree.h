//
// Created by HuanLing on 2019/4/11.
//

#ifndef INDEX2_AVLTREE_H
#define INDEX2_AVLTREE_H
#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int key;
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
}AVLNode;
class AVLTree{
public:
    AVLTree(int* arr,int n){
        root = _createTree(arr,n);
    }
private:
    AVLNode* root;
    AVLNode* _createTree(int*,int );
    AVLNode* _AVL_add(AVLNode* , int , int );
    void _in_Order(AVLNode* , vector<int> );
    bool _isBST(AVLNode* );
    int _getBalanceFactor(AVLNode* );
    bool _isBalanced(AVLNode*);
    AVLNode* _rightRotate(AVLNode* );
    AVLNode* _leftRotate(AVLNode* );
    AVLNode* _AVL_minimum(AVLNode*);
    AVLNode* _AVL_remove(AVLNode*,int key);
    int _getHeight(AVLNode* );
    void _inOrder(AVLNode*);
public:
    AVLNode* AVL_add(int key,int value);
    AVLNode* AVL_remove(int key);
    AVLNode* getRoot();
    void inOrder();
};
//================PUBLIC=========================
//============用户调用的函数=======================
//向二叉平衡树 添加一个节点
AVLNode* AVLTree::AVL_add(int key,int value){
    _AVL_add(root,key,value);
}
//向二叉平衡树 删除一个节点
AVLNode* AVLTree::AVL_remove(int key){
    _AVL_remove(root,key);
}
//获取二叉平衡树根节点
AVLNode* AVLTree::getRoot(){
    return root;
}
//二叉平衡树前序遍历
void AVLTree::inOrder(){
    _inOrder(root);
}

//================PUBLIC=========================


//================PRIVATE========================
/**
 *
 * @param arr 数组
 * @param n   数组大小
 * @return    返回根节点
 * 创建树
 */
AVLNode* AVLTree::_createTree(int* arr, int n){
    AVLNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = _AVL_add(root,arr[i],arr[i]);
    }

    return root;
}
/**
 *
 * @param node 根节点
 * @param keys 一个不定长数组存储前序遍历
 * 中序遍历
 */
void AVLTree::_in_Order(AVLNode* node, vector<int> keys){
    if(node == NULL)
        return;

    _in_Order(node->left, keys);
    keys.push_back(node->key);
    _in_Order(node->right, keys);
}
/**
 *
 * @param root 根节点
 * @return 返回为boolean
 * 判断是否为BST
 */
bool AVLTree::_isBST(AVLNode* root){
    vector<int> keys;
    _in_Order(root, keys);
    for(int i = 1 ; i < keys.size() ; i ++)
        if(keys[i-1]> keys[i] > 0)
            return false;
    return true;
}
/**
 * @param root  一个节点
 * @return 返回一个int
 * 返回一个节点的高度
 */
int AVLTree::_getHeight(AVLNode* root){
    if(root == NULL)
        return 0;
    return root->height;
}
/**
 * @param root  一个节点
 * @return 返回一个整形值
 *  获取平衡因子
 */
int AVLTree::_getBalanceFactor(AVLNode* root){
    if(root == nullptr)
        return 0;
    return _getHeight(root->left) - _getHeight(root->right);
}
/**
 * @param node 传入一个节点
 * @return      返回一个boolean
 *  返回是否平衡
 */
bool AVLTree::_isBalanced(AVLNode* node){

    if(node == NULL)
        return true;

    int balanceFactor = _getBalanceFactor(node);
    if(abs(balanceFactor) > 1)
        return false;
    return _isBalanced(node->left) && _isBalanced(node->right);
}
/**
 * @param y 节点
 * @return  返回根节点
 * 右旋转返回根节点
 */
AVLNode* AVLTree::_rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T3 = x->right;
    x->right = y;
    y->left = T3;
    y->height=max(_getHeight(y->left),_getHeight(y->right))+1;
    x->height=max(_getHeight(x->left),_getHeight(x->right))+1;
    return x;
}
/**
 * @param y 节点
 * @return  返回根节点
 * 左旋转返回根节点
 */
AVLNode* AVLTree::_leftRotate(AVLNode* y) {
    AVLNode* x = y->right;
    AVLNode* T3 = x->left;
    x->left = y;
    y->right = T3;
    y->height=max(_getHeight(y->left),_getHeight(y->right))+1;
    x->height=max(_getHeight(x->left),_getHeight(x->right))+1;
    return x;
}
/**
 * @param node  添加的根节点
 * @param key   键
 * @param value 值
 * @return      返回根节点
 * 向一个node添加元素
 */
AVLNode* AVLTree::_AVL_add(AVLNode* node, int key, int value){
    if(node == NULL)
        return new AVLNode(key,value);
    if(key < node->key)
        node->left = _AVL_add(node->left,key,value);
    else if(key > node->key){
        node->right = _AVL_add(node->right,key,value);
    } else
        node->value = value;

    node->height = 1 + max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if(balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _rightRotate(node);

    if(balanceFactor > 1 && _getBalanceFactor(node->left) < 0){
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    if(balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _leftRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->left) > 0){
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    return node;

}
/**
 * @param node 一个节点
 * @return  返回最小的节点
 * 获取一个节点的最小值
 */
AVLNode* AVLTree::_AVL_minimum(AVLNode* node){
    if(node->left == NULL)
        return node;
    return _AVL_minimum(node->left);
}
/**
 * @param node 根节点
 * @param key  要删除的键
 * @return     返回根节点
 * 删除一个节点
 */
AVLNode* AVLTree::_AVL_remove(AVLNode* node, int key){

    if( node == NULL )
        return NULL;

    AVLNode*  retNode;
    if( key - node->key < 0 ){
        node->left = _AVL_remove(node->left , key);
        // return node;
        retNode = node;
    }
    else if(key- node-> key > 0 ){
        node->right = _AVL_remove(node->right, key);
        // return node;
        retNode = node;
    }
    else{   // key.compareTo(node.key) == 0

        // 待删除节点左子树为空的情况
        if(node->left == NULL){
            AVLNode* rightNode = node->right;
            node->right = NULL;
            retNode = rightNode;
        }

            // 待删除节点右子树为空的情况
        else if(node->right == NULL){
            AVLNode* leftNode = node->left;
            node->left = NULL;
            retNode = leftNode;
        }

            // 待删除节点左右子树均不为空的情况
        else{
            // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
            // 用这个节点顶替待删除节点的位置
            AVLNode* successor = _AVL_minimum(node->right);
            successor->right = _AVL_remove(node->right, successor->key);
            successor->left = node->left;

            node->left = node->right = NULL;

            retNode = successor;
        }
    }

    if(retNode == NULL)
        return NULL;

    // 更新height
    retNode->height = 1 + max(_getHeight(retNode->left), _getHeight(retNode->right));

    // 计算平衡因子
    int balanceFactor = _getBalanceFactor(retNode);

    // 平衡维护
    // LL
    if (balanceFactor > 1 && _getBalanceFactor(retNode->left) >= 0)
        return _rightRotate(retNode);

    // RR
    if (balanceFactor < -1 && _getBalanceFactor(retNode->right) <= 0)
        return _leftRotate(retNode);

    // LR
    if (balanceFactor > 1 && _getBalanceFactor(retNode->left) < 0) {
        retNode->left = _leftRotate(retNode->left);
        return _rightRotate(retNode);
    }

    // RL
    if (balanceFactor < -1 && _getBalanceFactor(retNode->right) > 0) {
        retNode->right = _rightRotate(retNode->right);
        return _leftRotate(retNode);
    }

    return retNode;
}
/**
 * @param node  传入一个根节点
 * 中序遍历
 */
void AVLTree::_inOrder(AVLNode* node){
    if(node == NULL)
        return;
    _inOrder(node->left);
    cout << node->key <<" ";
    _inOrder(node->right);
}
//================PRIVATE========================
//================================
#endif //INDEX2_AVLTREE_H
