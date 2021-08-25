#include<bits/stdc++.h>
using namespace std;
#define V 7

vector<int>graph[V],rev[V];
void addEdge(int u,int v)
{
    graph[u].push_back(v);
}
void dfs_1(int u,vector<bool> &visited,stack<int> &s)
{
    visited[u]=true;
    for(auto i=graph[u].begin();i!=graph[u].end();i++)
    {
        if(visited[*i]==true)
            continue;
        dfs_1(*i,visited,s);
    }
    s.push(u);
}
void reverse(){
    for(int i=0;i<V;i++)
    {
        for(auto j=graph[i].begin();j!=graph[i].end();j++)
        {
            rev[*j].push_back(i);
        }
    }
}
void dfs_2(int u,vector<bool> &visited)
{
    cout<<u<<" ";
    visited[u]=true;
    for(auto i=rev[u].begin();i!=rev[u].end();i++)
    {
        if(visited[*i]==true)
            continue;
        dfs_2(*i,visited);
    }
}
void findSSC_Kosaraju()
{
    stack<int> s;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            dfs_1(i,visited,s);
    }
    reverse();
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int count=1;
    while(s.empty()==false)
    {
        int curr=s.top();
        s.pop();
        if(visited[curr]==true)
            continue;
        cout<<"Component "<<count<<" - ";
        dfs_2(curr,visited);
        count++;
        cout<<endl;
    }
}
int main(){

    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,4);
    addEdge(4,0);
    addEdge(4,5);
    addEdge(4,6);
    addEdge(5,6);
    addEdge(6,5);
    findSSC_Kosaraju();
    return 0;
}