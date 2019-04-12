//
// Created by HuanLing on 2019/4/12.
//

#ifndef INDEX2_LIST_H
#define INDEX2_LIST_H

#include "bits/stdc++.h"
using namespace std;
typedef  struct node{
    int val;
    struct node* next;
    node():next(NULL),val(0){};
    node(int a):val(a){};
}listnode;
class List{
public:
    List(){
        root = NULL;
    }
    List(int* arr,int n){
        root = _create_list(arr,n);
    }
private:
    listnode* _create_list(int* , int );
    listnode* _add_Element(listnode*  ,int ,int );
    listnode* _add_head(listnode*  ,int );
    listnode* _add_tail(listnode*  ,int );
    listnode* _remove_Element(listnode*  ,int );
    listnode* _updata_Element(listnode*  , int,int );
    listnode* _remove_tail(listnode* );
    listnode* _remove_head(listnode* );
    vector<int> _find_Element(listnode*  , int );
public:
    listnode* root;
    listnode* create_list(int* , int );
    listnode* add_Element(int ,int );
    listnode* add_head(int );
    listnode* add_tail(int );
    listnode* remove_Element(int );
    listnode* updata_Element(int,int );
    listnode* remove_tail();
    listnode* remove_head();
    vector<int> find_Element(int );
};
//初始化单链表
listnode* List::create_list(int* arr, int len){
    return  _create_list(arr,len);
}
//在一个某个位置后添加元素
listnode* List::add_Element(int a,int index){
        return _add_Element(root,a,index);
}
//在表头插入
listnode* List::add_head(int a){
    return _add_head(root,a);
}
//在表尾部插入
listnode* List::add_tail(int a){
    return _add_tail(root,a);
}
//删除某个位置上的元素
listnode* List::remove_Element(int index){
    return _remove_Element(root,index);
}
//删除头元素
listnode*  List::remove_head(){
    return _remove_head(root);
}
 //删除尾部
listnode*  List::remove_tail(){
    return _remove_tail(root);
}

//查找元素
vector<int>  List::find_Element( int a) {
    return _find_Element(root,a);
}

//修改元素值

listnode*  List::updata_Element(int a,int index){
    return _updata_Element(root,a,index);
}
//=====================PRIVATR=====================
/**
 *
 * @param arr  数组
 * @param len  数组长度
 * @return     返回根节点
 * 初始化单链表
 */
listnode* List::_create_list(int* arr, int len){
    listnode* dummmyhead = new listnode();
    listnode* tail = dummmyhead;
    if(len < 0)
        return dummmyhead->next;
    for (int i = 0; i < len; ++i) {
        listnode* temp = new listnode();
        temp->val = arr[i];
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    return dummmyhead->next;
}

/**
 *
 * @param head   头结点
 * @param a      节点的值
 * @param index  索引位置
 * @return       返回添加根节点
 * 在一个某个位置后添加元素
 */
listnode* List::_add_Element(listnode* head ,int a,int index){
    assert(index > 0);
    listnode* temp = new listnode(a);
    listnode* temphead = head;
    for (int i = 0; i < index-1 && temphead->next != NULL; ++i)
        temphead = temphead->next;
    temp->next = temphead->next;
    temphead->next = temp;
    return head;
}
/**
 * @param head 头结点
 * @param a    节点的值
 * @return     返回添加根节点
 * 在表头插入
 */
listnode* List::_add_head(listnode* head ,int a){
    listnode* temp = new listnode(a);
    listnode* temphead = head;
    temp->next = head;
    head = temp;
    return head;
}

/**
 * @param head 头结点
 * @param a    节点的值
 * @return     返回添加根节点
 * 在表尾部插入
 */
listnode* List::_add_tail(listnode* head ,int a){
    listnode* temp = new listnode(a);
    listnode* temphead = head;
    while(temphead->next != nullptr) temphead= temphead->next;
    temp->next = temphead->next;
    temphead->next = temp;
    return head;
}
/**
 * @param head 头结点
 * @param index 索引
 * @return  返回删除的节点
 * 删除某个位置上的元素
 */
listnode* List::_remove_Element(listnode* head ,int index){
    assert(index > 0);
    listnode* temphead = head;
    for (int i = 1; i < index-1 && temphead->next != NULL; ++i)
        temphead = temphead->next;
    temphead->next = temphead->next->next;
    return head;
}
/**
 * @param head  头结点
 * @return  返回删除的节点
 * 删除头元素
 */
listnode*  List::_remove_head(listnode* head){
    listnode* temphead = head;
    head = head->next;
    temphead->next = NULL;
    return head;
}

/**
 * @param head  头结点
 * @return      返回删除的节点
 * 删除尾部
 */
listnode*  List::_remove_tail(listnode* head){
    listnode* temphead = head;
    while(temphead->next->next != NULL)
        temphead = temphead->next->next;
    temphead->next = NULL;
    return head;
}

/**
 * @param p 头结点
 * @param a 节点得值
 * @return  返回一个vector
 * 查找元素
 */
vector<int>  List::_find_Element(listnode* p , int a) {
    int i = 1;
    vector<int> temp(0);
    while (p != NULL) {
        if (p->val == a)
            temp.push_back(i);
        p = p->next;
        i++;
    }

    return temp;
}
/**
 * @param head 头结点
 * @param a    节点值
 * @param index 索引
 * @return  返回根节点
 * 修改元素值
 */
listnode*  List::_updata_Element(listnode* head , int a,int index){
    assert(index > 0);
    listnode* temphead = head;
    for (int i = 1; i <= index-1 && temphead->next != NULL; ++i)
        temphead = temphead->next;
    temphead->val = a;
    return head;
}

//=====================PRIVATR=====================



#endif //INDEX2_LIST_H
