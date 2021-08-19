#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//We detect cycle in an undirected graph using dfs
void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
    //Since graph is undirected
    graph[v].push_back(u);
}
bool dfsSearch(vector<int>graph[],vector<bool> &visited,int pnode,int cnode)
{
    static bool cycle=false;
    visited[cnode]=true;
    for(auto itr=graph[cnode].begin();itr!=graph[cnode].end();itr++)
    {
        if(*itr==pnode)
        {
            continue;
        }
        if(visited[*itr]==true)
        {
            return true;
        }
        cycle=dfsSearch(graph,visited,cnode,*itr);
        if(cycle==true)
            break;
    }
    return cycle;
}
bool detectCycle(vector<int>graph[],int v)
{
    vector<bool> visited(v,false);
    int pnode=-1;//parent node of graph
    bool cycle=false;
    for(int i=0;i<v;i++)
    {
        //i is current node or cnode
        if(visited[i]==false)
            cycle=dfsSearch(graph,visited,pnode,i);
        if(cycle==true)
            break;
    }
    return cycle;
}
int main(){
    int v=5;
    vector<int>graph[v];
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    bool flag=detectCycle(graph,v);
    cout<<flag<<endl;
    return 0;
}