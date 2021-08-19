#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;
//We use DFS in top sort and store order in reverse,watch online video
void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
}

void dfs(vector<int>graph[],vector<bool> &visited,stack<int> &traversal,int e)
{
    visited[e]=true;
        
    for(vector<int>::iterator i=graph[e].begin();i!=graph[e].end();i++)
    {
        if(visited[*i]!=true){
            dfs(graph,visited,traversal,*i);
        }
    }
    traversal.push(e);
 
} 
vector<int> topSort(int v, vector<int> graph[]) 
{
    vector<bool> visited(v,false);
    vector<int> order;
    stack<int> traversal;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {   
            dfs(graph,visited,traversal,i);    
        }
    }
    while(traversal.empty()==false)
    {
        order.push_back(traversal.top());
        traversal.pop();
    }
               
    return order;
        
}
int main(){
    int v=5;
    vector<int> graph[v];
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int> order=topSort(v,graph);
    cout<<order.size()<<endl;
    for(auto i=order.begin();i!=order.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}