#include<bits/stdc++.h>
using namespace std;


//Below alogorthm is used for detect cycle in Undirected graph
//Complexity is O(E) where id no of edges

vector<int>parent;
vector<int>size;
struct edge{
    int src;
    int des;
    int cost;
    edge(int s,int d,int c)
    {
        src=s;
        des=d;
        cost=c;
    }
};
void set_value(int  V)
{
    for(int i=0;i<V;i++)
    {
        parent.push_back(i);
        size.push_back(1);
    }
}
int find_set(int v)
{
    //below is path compression optimization
    //it is done so that all the nodes in set point to the main
    //parent node
    if(v==parent[v])
        return v;
    parent[v]=find_set(parent[v]);
}
void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        //this is union by size
        //in this we merge two sets by mergin the smaller 
        //set with bigger set
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
bool cmp(edge a,edge b)
{
    return a.cost < b.cost;
}
vector<edge> Kruskal(vector<edge> &edges,int V)
{
    vector<edge>mst;
    sort(edges.begin(),edges.end(),cmp);
    int e=0;
    int i=0;
    while(e<V-1 and i<edges.size())
    {
        int a=find_set(edges[i].src);
        int b=find_set(edges[i].des);
        if(a!=b)
        {
            mst.push_back(edge(edges[i].src,edges[i].des,edges[i].cost));
            union_set(a,b);
            e++;
        }
        i++;
    }
    return mst;
}
int main(){
    int V=5;
    vector<edge>edges;
    set_value(V);
    edges.push_back(edge(0,1,5));
    edges.push_back(edge(1,2,10));
    edges.push_back(edge(1,4,25));
    edges.push_back(edge(4,2,5));
    edges.push_back(edge(2,3,15));
    

    vector<edge> mst=Kruskal(edges,V);
    for(int i=0;i<mst.size();i++)
    {
        cout<<"Source "<<mst[i].src<<" Destination "<<mst[i].des
            <<" Cost "<<mst[i].cost<<endl;
    }
  
}