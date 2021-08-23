#include<bits/stdc++.h>
using namespace std;


//Below alogorthm is used for detect cycle in Undirected graph
//Complexity is O(E) where id no of edges

vector<int>parent;
vector<int>size;
void set_value(int  V)
{
    for(int i=0;i<V;i++)
    {
        parent.push_back(i);
        size.push_back(1);
    }
}
int find_set(int v)
{
    //below is path compression optimization
    //it is done so that all the nodes in set point to the main
    //parent node
    if(v==parent[v])
        return v;
    parent[v]=find_set(parent[v]);
}
void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        //this is union by size
        //in this we merge two sets by mergin the smaller 
        //set with bigger set
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
bool isCyclic(vector<pair<int,int>> &edges)
{
    for(auto i:edges)
    {
        int a=find_set(i.first);
        int b=find_set(i.second);
        if(a==b)
            return true;
        union_set(a,b);
    }
    return false;
}
int main(){
    int V=5;
    vector<pair<int,int>>edges;
    set_value(V);
    edges.push_back({0,1});
    edges.push_back({0,3});
    edges.push_back({1,2});
    edges.push_back({2,4});
    edges.push_back({2,3});
    if(isCyclic(edges))
        cout<<"Cycle is present"<<endl;
    else cout<<"Cycle is not present"<<endl;
    return 0;
}