//
// Created by HuanLing on 2019/4/14.
//

#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 100
struct edge
{
    int x,y;
    int w;
}e[MAX];
int fa[MAX];
int rank[MAX];
int sum;
int cmp(edge a,edge b)//排序函数
{
    if(a.w!=b.w)
        return a.w<b.w;
    else
    {
        return a.x<b.x;
    }
}
void make_set(int x)//初始化节点
{
    fa[x]=x;
    rank[x]=0;
}
int find(int x)//查找父节点
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}


void union_set(int x,int y,int w)//合并节点
{
    if(rank[x]>rank[y])
    {
        rank[y]=x;
    }
    else  if(rank[x]<rank[y])
    {
        rank[x]=y;
    }
    else
    {
        rank[x]++;
        rank[y]=x;
    }
    sum+=w;//总权值加上w
}
int main()
{
    int x,y,w;
    int m,n;//n是点,m是边
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        e[i].x=x;
        e[i].y=y;
        e[i].w=w;
        make_set(x);
        make_set(y);
    }
    sort(e,e+m,cmp);
    sum=0;
    for(int  i=0;i<n;i++)
    {
        x=find(e[i].x);
        y=find(e[i].y);
        w=e[i].w;
        if(x!=y)
        {
            union_set(x,y,w);
        }
    }
    cout<<sum<<endl;
    return 0;
}