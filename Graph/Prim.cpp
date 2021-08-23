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
//Below is custom comparator for multiset used as priority queue
struct cmp{
    bool operator()(const node &a,const node &b)
    {
        return a.cost<b.cost;
    }
};
int V;
vector<pair<int,int>>mst[10];
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

        for(auto i=graph[e.u].begin();i!=graph[e.u].end();i++)
        {
            
            if(visited[i->first]==true)
                continue;
            pq.insert(node(i->first,e.u,i->second));
        }
    }
}
int main(){
    V=9;
    vector<pair<int,int>> graph[V];
    addEdge(graph,0,1,4);
    addEdge(graph,0,7,8);
    addEdge(graph,1,2,8);
    addEdge(graph,1,7,11);
    addEdge(graph,7,8,7);
    addEdge(graph,7,6,1);
    addEdge(graph,2,8,2);
    addEdge(graph,2,5,4);
    addEdge(graph,2,3,7);
    addEdge(graph,6,5,2);
    addEdge(graph,6,8,6);
    addEdge(graph,5,3,14);
    addEdge(graph,5,4,10);
    addEdge(graph,3,4,9);
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