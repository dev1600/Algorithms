#include <bits/stdc++.h>
using namespace std;
#define V 6
vector<int>graph[V];

void addEdge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void dfs(int u,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<bool> &articulation_point)
{
    static int tim=0;
    disc[u]=low[u]=tim;
    tim+=1;
    int children=0;
    for(auto i=graph[u].begin();i!=graph[u].end();i++)
    {
        if(disc[*i]==-1)
        {
            children+=1;
            parent[*i]=u;
            dfs(*i,disc,low,parent,articulation_point);
            low[u]=min(low[u],low[*i]);

            if(parent[u]==-1 and children>1) //1st case if u is root of dfs tree
            {
                articulation_point[u]=true;
            }
            if(parent[u]!=-1 and low[*i]>=disc[u])//Atleast 1 component will get separated
            {
                articulation_point[u]=true;
            }
        }
        else if(*i!=parent[u]) //Condition for back edge
        {
            low[u]=min(low[u],disc[*i]);
        }
        
    }
}
void findAp_Tarjan(){
    vector<int>disc(V,-1),low(V,-1),parent(V,-1);
    vector<bool>articulation_point(V,false);

    for(int i=0;i<V;i++)
    {
        if(disc[i]==-1)
            dfs(i,disc,low,parent,articulation_point);
    }
    cout<<"Articulation Points are: ";
    for(int i=0;i<V;i++)
    {
        if(articulation_point[i]==true)
            cout<<i<<" ";
    }
    cout<<endl;
}
int main(){

    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(1,3);
    addEdge(3,4);
    addEdge(3,5);
    findAp_Tarjan();
    return 0;
}