#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

void addEdge(vector<pair<int,int>> graph[],int u,int v,int cost)
{
    graph[u].push_back(make_pair(v,cost));

    //For Directed graph remove below line
    graph[v].push_back(make_pair(u,cost));
}
void printGraph(vector<pair<int,int>> graph[],int n)
{
    for(int i=0;i!=n;i++)
    {
        cout<<"Element of "<<i;
        for(auto j=graph[i].begin();j!=graph[i].end();j++)
        {
            cout<<"->"<<j->first<<"("<<j->second<<")";
        }
        cout<<endl;
    }
}
int main(){
    int v=5;
    vector<pair<int,int>> graph[v];

    addEdge(graph,1,2,20);
    addEdge(graph,1,4,10);
    addEdge(graph,2,3,15);
    addEdge(graph,2,4,5);
    printGraph(graph,v);

    return 0;


}