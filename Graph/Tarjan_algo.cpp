#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
}
void dfs(vector<int>graph[],int u,vector<int> &disc,vector<int> &low,stack<int> &curr,vector<bool> &inStack)
{
    static int time=0;
    disc[u]=low[u]=time;
    time+=1;
    curr.push(u);
    inStack[u]=true;
    for(auto i=graph[u].begin();i!=graph[u].end();i++)
    {
        if(disc[*i]==-1)
        {
            dfs(graph,*i,disc,low,curr,inStack);
            low[u]=min(low[u],low[*i]);
        }
        //Means node has been visited once before 
        else {
            //condition for back-edge and cross edge
            if(inStack[*i]==true)
            {
                //IF TRUE MEANS  its a back edge
                low[u]=min(low[u],disc[*i]);
            }
        }
    }
    if(low[u]==disc[u])//means u is head of strongly connected component(SCC)
    {
        cout<<"SSC is ";
        while(curr.top()!=u)
        {
            cout<<curr.top()<<" ";
            inStack[curr.top()]=false;
            curr.pop();
        }
        cout<<curr.top()<<endl;
        inStack[curr.top()]=false;
        curr.pop();

    }
}
void findSSC_Tarjan(vector<int>graph[],int V)
{
    vector<int>disc(V,-1),low(V,-1);
    vector<bool>inStack(V,false);
    stack<int>curr;
    for(int i=0;i<V;i++)
    {
        if(disc[i]==-1)
            dfs(graph,i,disc,low,curr,inStack);
    }
}
int main(){
    int V=7;
    vector<int>graph[V];
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,3,4);
    addEdge(graph,4,0);
    addEdge(graph,4,5);
    addEdge(graph,4,6);
    addEdge(graph,5,6);
    addEdge(graph,6,5);
    findSSC_Tarjan(graph,V);
    return 0;
}