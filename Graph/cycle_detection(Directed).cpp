#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
}
bool dfs(vector<int>graph[],vector<bool>&black,vector<bool>&grey,int e)
{
    static bool cycle=false;
    grey[e]=true;
    for(auto i=graph[e].begin();i!=graph[e].end();i++)
    {
        if(black[*i]==true)
            continue;
        if(grey[*i]==true)
            return true;

        cycle=dfs(graph,black,grey,*i);
        if(cycle==true)
            return cycle;
    }
    grey[e]=false;
    black[e]=true;
    return cycle;
}
bool detectcycle(vector<int>graph[],int v)
{
    vector<bool> black(v,false);//for nodes that have been visited/same as visited
    vector<bool> grey(v,false);//for nodes that have to be visited
    bool cycle=false;
    for(int i=0;i<v;i++)
    {
        if(black[i]==false)
            cycle=dfs(graph,black,grey,i);
    }
    return cycle;

}
int main(){
    int v=6;
    vector<int>graph[v];
// 5 3
// 3 1
// 1 2
// 2 4
// 4 0
    // addEdge(graph,1,2);
    // addEdge(graph,1,4);
    // addEdge(graph,2,3);
    // addEdge(graph,2,4);
    addEdge(graph,5,3);
    addEdge(graph,3,1);
    addEdge(graph,1,2);
    addEdge(graph,2,4);
    addEdge(graph,4,0);
    bool cycle=detectcycle(graph,v);
    cout<<cycle<<endl;
}