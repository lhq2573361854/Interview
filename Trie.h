//
// Created by HuanLing on 2019/4/12.
//
#ifndef INDEX2_TRIE_H
#define INDEX2_TRIE_H
#include <bits/stdc++.h>
using namespace std;
typedef  struct Node{
    int isWord;
    map<char, Node*> next;
    Node(int isWord){
        this->isWord = isWord;
    }
    Node(){
        this->isWord = 0;
    }
}dirNode;
class Trie{
public:
    void dir_add(string word);
    int  dir_contains(string word);
    int  isPrefix(string prefix);
private:
    dirNode* root;
    void _dir_add(string word,dirNode* root);
    int _dir_contains(string word,dirNode* root);
    int _isPrefix(string prefix,dirNode* root);
};

void Trie::dir_add(string word){
    _dir_add(word,root);
}
int  Trie::dir_contains(string word){
    return _dir_contains( word, root);
}
int  Trie::isPrefix(string prefix){
    return _isPrefix(prefix,root);
}

/**
 * 字典树中添加单词
 * @param word 单词
 * @param root 根节点
 */
void Trie::_dir_add(string word,dirNode* root){
    dirNode* cur = root;
    for (int i = 0; i < word.size(); ++i){
        if(cur->next[word[i]] == NULL){
            cur->next[word[i]] = new dirNode();
        }
        cur = cur->next[word[i]];
    }
    if(!cur->isWord){
        cur->isWord = 1;
    }
}
/**
 * 查询单词word是否在Trie中
 * @param word 单词
 * @param root 根节点
 * @return
 */
int Trie::_dir_contains(string word,dirNode* root){
    dirNode* cur =root;
    for (int i = 0; i < word.size(); ++i) {
        if(cur->next[word[i]] == NULL){
            return 0;
        }
        cur = cur->next[word[i]];
    }
    return cur->isWord;
}
/**
 * 前缀查询
 * @param prefix  前缀
 * @param root    根节点
 * @return
 */
int Trie::_isPrefix(string prefix,dirNode* root){

    dirNode* cur = root;
    for(int i = 0 ; i < prefix.length() ; i ++){
        char c = prefix[i];
        if(cur->next[c] == NULL)
            return false;
        cur = cur->next[c];
    }
    return true;
}
//=============基础数据结构(字典树)============================

#endif //INDEX2_TRIE_H
