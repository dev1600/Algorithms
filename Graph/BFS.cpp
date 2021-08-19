#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
    //Since graph is directed
}
//assuming bfs startes from 1
vector<int> bfs(vector<int>graph[],int v)
{
    vector<bool> visited(v,false);
    vector<int>traversal;
    queue<int> q;
    q.push(1);
    while(!(q.empty()))
    {
        int e=q.front();
        q.pop();
        if(visited[e]==true)
            continue;
        visited[e]=true;
        traversal.push_back(e);
        for(auto i=graph[e].begin();i!=graph[e].end();i++)
        {  
            if(visited[*i]==true)
                continue;
            else{
                q.push(*i);

            }
        }
    }
    return traversal;
}
int main(){
    int v=5;
    vector<int>graph[v];
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int> traversal=bfs(graph,v);
    cout<<"BFS->";
    for (int i = 0; i < traversal.size(); i++)
    {
        cout<<traversal[i]<<" ";
    }
    cout<<endl;
    

    
}