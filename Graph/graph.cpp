#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct vertex{
    int node;
    int cost;
};
void addEdge(vector<vertex>graph[],int u,int v,int cost)
{
    vertex node1;
    node1.node=v;
    node1.cost=cost;
    graph[u].push_back(node1);
    node1.node=u;
    //To implement a Directed Graph remove below line
    graph[v].push_back(node1);

}
void printGraph(vector<vertex> graph[],int v)
{
    cout<<"Edges are as follows"<<endl;
    for(auto i=0;i!=v;i++)
    {
        cout<<"Edges of "<<i;
        for (auto j = graph[i].begin(); j!=graph[i].end(); j++)
        {
            cout<<"->"<<j->node<<"("<<j->cost<<")";
        }
        cout<<endl;
        
    }
}
int main(){
    //No of vertex
    int v=5;
    vector<vertex>graph[v];

    addEdge(graph,1,2,20);
    addEdge(graph,1,4,10);
    addEdge(graph,2,3,15);
    addEdge(graph,2,4,5);
    printGraph(graph,v);

    return 0;
}