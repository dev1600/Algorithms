#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
    //Since graph is undirected
    graph[v].push_back(u);
}
//passing vectors as reference  by using &
void dfsSearch(vector<int> graph[],vector<bool> &visited,vector<int> &traversal,int e)
{
        visited[e]=true;
        traversal.push_back(e);
        for(auto i=graph[e].begin();i!=graph[e].end();i++)
        {
           if(visited[*i]!=true){
                dfsSearch(graph,visited,traversal,*i);

           }
        }

}
vector<int> dfs(vector<int>graph[],int v)
{
    vector<bool> visited(v,false);
    int e=1;
    vector<int>traversal;
    dfsSearch(graph,visited,traversal,e);
    return traversal;
}
int main(){
    int v=5;
    vector<int> graph[v];
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int> traversal=dfs(graph,v);
    cout<<traversal.size()<<endl;
    cout<<"DFS-";
    for (int i = 0; i < traversal.size(); i++)
    {
        cout<<traversal[i]<<" ";
    }

    return 0;
}