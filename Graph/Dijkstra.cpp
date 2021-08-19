#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> graph[],int u,int v,int cost)
{
    graph[u].push_back({v,cost});
    //Since graph is undirected
    graph[v].push_back({u,cost});
}
void shortestPath(vector<pair<int,int>>graph[],vector<int> &distance,int V,int source)
{
    //WE are gonna implement a multiset instead of pq 
    //same complexity
    multiset<pair<int,int>>pq;
    pq.insert({0,source});
    distance[source]=0;
    
    while(pq.empty()==false)
    {
        int curr_node=(*pq.begin()).second;
        int curr_cost=(*pq.begin()).first;
        pq.erase(pq.begin());
        for(auto i=graph[curr_node].begin();i!=graph[curr_node].end();i++)
        {
            int next_cost=(*i).second+curr_cost;
            if(next_cost<distance[(*i).first])
            {
                distance[(*i).first]=next_cost;
                //we add the curr node to pq
                pq.insert({next_cost,(*i).first});
            }
        }

    }

}
int main(){
    int V=5;
    vector<pair<int,int>>graph[V];
    vector<int>distance(V,INT_MAX);
    int source=4;
    //u v cost
    addEdge(graph,0,1,2);
    addEdge(graph,0,3,1);
    addEdge(graph,3,2,3);
    addEdge(graph,2,4,1);
    addEdge(graph,1,4,5);
    addEdge(graph,1,2,4);
    shortestPath(graph,distance,V,source);
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }

}