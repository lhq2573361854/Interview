//
// Created by HuanLing on 2019/4/12.
//

#ifndef INDEX2_RBTREE_H
#define INDEX2_RBTREE_H
#define BLACK false
#define RED true
#include<bits/stdc++.h>
using namespace std;
typedef struct  Node{
    int key;
    int value;
    Node* left;
    Node* right;
    bool color;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        color = RED;
    }
}RBNode;
class RBTree{
public:
    RBTree(){

    }
private:
    bool _isRed(RBNode*);
    void _flipColor(RBNode*);
    RBNode* _RB_add(RBNode*, int, int);
    RBNode* _RB_rightRotate(RBNode* node);
    RBNode* _RB_leftRotate(RBNode* node);
};

bool RBTree::_isRed(RBNode* node){
    if(node == NULL)
        return BLACK;
    return node->color;
}
//颜色翻转
void  RBTree::_flipColor(RBNode* node){
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}
//红黑树的左旋转
RBNode*  RBTree::_RB_leftRotate(RBNode* node){
    RBNode* x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = RED;
    return x;
}
//红黑树的右旋转
RBNode*  RBTree::_RB_rightRotate(RBNode* node){
    RBNode* x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    node->color = RED;
    return x;
}
//添加元素
RBNode*   RBTree::RBTree::_RB_add(RBNode* node, int key, int value){
    if(node == NULL)
        return new RBNode(key,value);
    if(key < node->key)
        node->left = _RB_add(node->left,key,value);
    else if(key > node->key){
        node->right = _RB_add(node->right,key,value);
    } else
        node->value = value;
    if(_isRed(node->right) && !_isRed(node->left))
        node = _RB_leftRotate(node);
    if(_isRed(node->right) && _isRed(node->left->left))
        node = _RB_rightRotate(node);
    if(_isRed(node->left) && _isRed(node->right))
        _flipColor(node);
}


#endif //INDEX2_RBTREE_H
