#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int cost;
    node(int u,int v,int cost)
    {
        this->u=u;
        this->v=v;
        this->cost=cost;
    }
};
struct cmp{
    bool operator()(const node &a,const node &b)
    {
        return a.cost<b.cost;
    }
};
int V;
vector<pair<int,int>>mst[6];
void addEdge(vector<pair<int,int>>graph[],int u,int v,int cost)
{
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
void Prim(vector<pair<int,int>>graph[])
{
    multiset<node,cmp>pq;
    vector<bool>visited(V,false);
    pq.insert(node(0,-1,0));
    while(pq.empty()==false)
    {
        node e=*(pq.begin());
        pq.erase(pq.begin());
        if(visited[e.u]==true)
            continue;
        visited[e.u]=true;
        mst[e.u].push_back({e.v,e.cost});
        // cout<<e.u<<" "<<e.v<<" Cost= "<<e.cost<<endl;
        for(auto i=graph[e.u].begin();i!=graph[e.u].end();i++)
        {
            
            if(visited[i->first]==true)
                continue;
            pq.insert(node(i->first,e.u,i->second));
            // cout<<i->first<<endl;
        }
    }
}
int main(){
    V=5;
    vector<pair<int,int>> graph[V];
    addEdge(graph,0,1,5);
    addEdge(graph,1,2,10);
    addEdge(graph,1,4,25);
    addEdge(graph,2,3,15);
    addEdge(graph,2,4,5);
    Prim(graph);
    for(int i=0;i<V;i++)
    {
        for(auto j=mst[i].begin();j!=mst[i].end();j++)
        {
            cout<<i<<" "<<j->first<<" Cost= "<<j->second<<endl;
        }
    }
    return 0;
}