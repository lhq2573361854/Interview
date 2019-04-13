//
// Created by HuanLing on 2019/4/14.
//
#include<iostream>
using namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int Prim(int graph[][MAX], int n)//二维数组作为参数如何使用？
{
    int sta[MAX];//存放某一条边的起点值
    int lowcost[MAX];//存放以i为终点的的边的最小的权值
    int min,minid,sum=0;//min用来存放最小权值，minid用来存放权值最小的边所对应的终点
    for(int i=2;i<=n;i++)
    {
        lowcost[i]=graph[1][i];//初始化lowcost[i]，并把他们的初始值都看作是从节点1出发到i的权值
        sta[i]=1;//起点赋值为1
    }
    sta[1]=0;//节点1进入最小生成树
    for(int h=2;h<=n;h++)
    {
        min=MAXCOST;//找到最小的，先来个较大值
        for(int j=2;j<=n;j++)
        {
            if(lowcost[j]<min&&lowcost[j]!=0)//如果找到权值较小的就赋值给min，并把终点j赋值给minid。
            {    min=lowcost[j]; minid=j;}
        }
        lowcost[minid]=0;//这条边已经进入最小生成树，所以把值置为0
        sum+=min;
        for(int s=2;s<=n;s++)
        {
            if(lowcost[s]<graph[minid][s])//如果原先的lowcost[j]的值大于以minid为起点到终点j的权值，则更新它，并把起点更新为minid
            {
                lowcost[s]=graph[minid][s];
                sta[s]=minid;
            }
        }
    }
    return sum;

}
int main()
{
    int m,n,x,y,cost;
    cout<<"请输入节点数目和边的数目："<<endl;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            graph[i][j]=MAXCOST;

    for(int k=1;k<=n;k++)
    {
        cin>>x>>y>>cost;
        graph[x][y]=graph[y][x]=cost;
    }
    cost= Prim(graph,n);
    cout<<cost<<endl;
    return 0;
}
