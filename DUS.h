//
// Created by HuanLing on 2019/4/12.
//

#ifndef INDEX2_DUS_H
#define INDEX2_DUS_H
class DUS{
private:
    int* parent ;
    int* rank;
    int  _find(int );
    void _Union(int,int );
public:
    DUS(int len){
        for (int i = 0; i < len; ++i) {
            rank[i] =1;
            parent[i]=i;
        }
    }
};

/**
 * 并查集的查
 * @param p  查询一个节点
 * @return
 */
int DUS::_find(int p){
    while( p != parent[p] ){
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

/**
 * 并查集的合并
 * @param p  一个节点
 * @param q  一个节点
 */
void DUS::_Union(int p,int q){
    int pRoot = _find(p);
    int qRoot = _find(q);

    if(pRoot == qRoot)
        return;
    if( rank[pRoot] < rank[qRoot] )
        parent[pRoot] = qRoot;
    else if( rank[qRoot] < rank[pRoot])
        parent[qRoot] = pRoot;
    else{ // rank[pRoot] == rank[qRoot]
        parent[pRoot] = qRoot;
        rank[qRoot] += 1;   // 此时, 我维护rank的值
    }
}
#endif //INDEX2_DUS_H
