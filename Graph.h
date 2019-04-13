//
// Created by HuanLing on 2019/4/13.
//

#ifndef INDEX2_GRAPH_H
#define INDEX2_GRAPH_H
#define _MAX 2020
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int x,y;
    int w;
}e[_MAX];

class Graph{
private:
    int n;
    int v;
    int w;
    int** arr;
    int* vis;
    bool** g;
    int** path;
    int* id;
    int* dis;
    int* rank;
    int* father;
    int sum;
    void dfs(int node);
    void dijstra();
    void dijstra_path();
    void floyd_path();
    void floyd_closure();
    void prim();
    void kruskal();
    int _find(int);
    void _union(int ,int ,int );
    void make_set(int x);
public:
    Graph(){

    }
    Graph(int** arr){
        this->arr = arr;
    }

};
/**
 * 获取一个图 邻接矩阵
 * @return
 */
int** getAdjacencyMatrix(){

}
/**
 * 邻接表
 */
vector<vector<int>> getAdjacencyList(){

}
/**
 * 连通图的dfs
 * @param node
 */
void Graph::dfs(int node) {

}
/**
 * 这是一个FLODY的有向图的最短路径 O(n^3)
 */
void Graph::floyd_path() {
    for(int  k = 0;k < n;k ++){
       for(int i = 0;i < n; i ++)
              for(int j = 0;j < n;j ++)
                    if(arr[i][j] > (arr[i][k] + arr[k][j])){
                    arr[i][j]= arr[i][k] + arr[k][j];
                    path[i][j]=k;
               }
      }
}
/**
 * 这是一个FLODY闭包算法
 */
void Graph::floyd_closure() {
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(k != i && k != j && i != j)
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }

    int nowans;
    int ans;
    for(int i = 1;i <= n;i++){
        nowans= 0;
        for(int j = 1;j <= n;j++){
            if(g[i][j]) nowans++;
            if(g[j][i]) nowans++;
        }
        if(nowans == n-1) ans++;
    }
    cout<<ans<<endl;

}
/**
 * 贪心规划
 */
void Graph::dijstra() {
    //初始化v[0]到v[i]的距离
    for(int i=1;i<=n;i++)
        dis[i] = arr[1][i];
    vis[1]=1;//标记v[0]点
    for(int i = 1; i <= n; i++){
        //查找最近点
        int min = INT_MAX,k = 0;
        for(int j = 0; j <= n; j++)
            if(!vis[w] && dis[j] < min)
                min = dis[w],k = j;
        vis[k] = 1;//标记查找到的最近点
        //判断是直接v[0]连接v[j]短，还是经过v[k]连接v[j]更短
        for(int j = 1; j <= n; j++)
            if(!vis[j] && min+arr[k][j] < dis[j])
                dis[j] = min+arr[k][j];
    }
}
/***
 * dijstra算法最短路径
 */
void Graph::dijstra_path() {
    const int N = 2020;
    vector<pair<int,int> >E[N];
    int n ,m;
    int dis[N];
    while(cin >> n>>m){
        for (int i = 0; i < N; ++i) {
            E[i].clear();
            dis[i] = 1e9;
        }
        for (int i = 0; i < n; ++i) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            E[x].push_back(make_pair(y,z));
            E[y].push_back(make_pair(x,z));
        }
        int s , t;
        cin >>s >>t;
        priority_queue<pair<int,int>> q;
        dis[s] = 0;
        q.push(make_pair(-dis[s],s));
        while(!q.empty()){
            int now = q.top().second;
            q.pop();
            for(int i = 0; i < E[now].size(); i ++){
                int v =E[now][i].first;
                if(dis[v] > dis[now]+ E[now][i].second){
                    dis[v] = dis[now]+E[now][i].second;
                    q.push(make_pair(-dis[v],v));
                }
            }
        }
        if(dis[t] == 1e9)
            cout << "-1" <<endl;
        else
            cout << dis[t] <<endl;

    }

}
/**
 * 贪心算法
 */
void Graph::prim() {
    int j,sum=0,count=1,k;
    vis[1] =1;
    while(count<n)
    {
        int min=INT_MAX;
        for(int  i=1;i<=n;i++){
            if(vis[i] == 0 && dis[i] < min){
                min = dis[i];
                j = i;
            }
        }
        vis[j]=1;
        count++;
        sum=sum+dis[j];
        //扫描当前顶点j所有的边，再以j为中间点，更新生成树到每一个非树顶点的距离；
        for(k = 1; k <= n; k ++){
            if(vis[k] == 0 && dis[k] > arr[j][k]){
                dis[k] = arr[j][k];
            }
        }
    }

}
int Graph::_find(int x) {
    return father[x]==x? x : father[x]=_find(father[x]);
}
void Graph::_union(int x,int y,int w) {

    int pRoot = _find(x);
    int qRoot = _find(y);

    if(pRoot == qRoot)
        return;
    if( rank[pRoot] < rank[qRoot] )
        father[pRoot] = qRoot;
    else if( rank[qRoot] < rank[pRoot])
        father[qRoot] = pRoot;
    else{ // rank[pRoot] == rank[qRoot]
        father[pRoot] = qRoot;
        rank[qRoot] += 1;   // 此时, 我维护rank的值
    }
        sum+=w;//总权值加上w
}
void Graph::make_set(int x){
    father[x]=x;
    rank[x]=0;
}
int cmp(edge a,edge b){
    if(a.w!=b.w)
        return a.w<b.w;
    else
        return a.x<b.x;

}
void Graph::kruskal() {
    int x,y,z;
    for(int  i=0;i<n;i++){
        _union(x,y,w);
     }
    return sum;
}
#endif //INDEX2_GRAPH_H
