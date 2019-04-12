//
// Created by HuanLing on 2019/4/12.
//

#ifndef INDEX2_SEGMENTTREE_H
#define INDEX2_SEGMENTTREE_H
#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
private:
    int* tree;
    int* data;
    int len;
    void _buildSegmentTree(int , int , int );
    int _leftChild(int );
    int _rightChild(int );
    int _query(int , int , int , int , int );
    void _set(int treeIndex, int l, int r, int index, int e);
public:
    SegmentTree(int* arr,int len){
        this->len = len;
        data = arr;
        tree = new int[4 * len]();
        _buildSegmentTree(0, 0, len-1);
    }
    int query(int , int );
    void set(int , int );
    void print();
};
//===================PUBLIC========================
//查询
int SegmentTree::query(int queryL, int queryR){

    if(queryL < 0 || queryL >= len ||
       queryR < 0 || queryR >= len || queryL > queryR)
        return -1;

    return _query(0, 0, len-1, queryL, queryR);
}
//设置
void SegmentTree::set(int index, int e){
    assert(index >= 0 || index < len);
    data[index] = e;
    _set(0, 0, len - 1, index, e);
}
//打印
void SegmentTree::print() {
    for (int i = 0; i < 4 * len; ++i) {
        cout << tree[i] <<" ";
    }
}
//===================PUBLIC========================
//===================PRIVATE===========================
/**
 * 构建线段树
 * @param treeIndex 树的索引
 * @param l         左索引
 * @param r         右索引
 */
void SegmentTree::_buildSegmentTree(int treeIndex, int l, int r){
    if(l == r){
        tree[treeIndex] = data[l];
        return;
    }
    int leftTreeIndex = _leftChild(treeIndex);
    int rightTreeIndex = _rightChild(treeIndex);

    // int mid = (l + r) / 2;
    int mid = l + (r - l) / 2;
    _buildSegmentTree(leftTreeIndex, l, mid);
    _buildSegmentTree(rightTreeIndex, mid + 1, r);

    tree[treeIndex] = tree[leftTreeIndex]+tree[rightTreeIndex];
}
/**
 * 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
 * @param index 树的索引
 * @return      左孩子节点的索引
 */
int SegmentTree::_leftChild(int index){
    return 2*index + 1;
}
/**
 * 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
 * @param index 树的索引
 * @return      左孩子节点的索引
 */
int SegmentTree::_rightChild(int index){
    return 2*index + 2;
}
/**
 * 在以treeIndex为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
 * @param treeIndex treeIndex为根
 * @param l         区间 left
 * @param r         区间 right
 * @param queryL    搜索区间 left
 * @param queryR    搜索区间 right
 * @return
 */
int SegmentTree::_query(int treeIndex, int l, int r, int queryL, int queryR) {
    if(l == queryL && r == queryR)
        return tree[treeIndex];
    int mid = l + (r - l) / 2;
    int leftTreeIndex = _leftChild(treeIndex);
    int rightTreeIndex = _rightChild(treeIndex);

    if(queryL >= mid + 1)
        return _query(rightTreeIndex, mid + 1, r, queryL, queryR);
    else if(queryR <= mid)
        return _query(leftTreeIndex, l, mid, queryL, queryR);

    int leftResult = _query(leftTreeIndex, l, mid, queryL, mid);
    int rightResult = _query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
    return (leftResult + rightResult);
}
/**
 * 打印线段树
 */
void SegmentTree::_set(int treeIndex, int l, int r, int index, int e){
    if(l == r){
        tree[treeIndex] = e;
        return;
    }
    int mid = l + (r - l) / 2;
    int leftTreeIndex = _leftChild(treeIndex);
    int rightTreeIndex = _rightChild(treeIndex);
    if(index >= mid + 1)
        _set(rightTreeIndex, mid + 1, r, index, e);
    else
        _set(leftTreeIndex, l, mid, index, e);

    tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
}
//===================PRIVATE===========================

#endif //INDEX2_SEGMENTTREE_H
