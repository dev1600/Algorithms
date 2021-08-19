#include<bits/stdc++.h>
using namespace std;

void sort(stack<int>&);
void insertSort(stack<int>&,int);

void sort(stack<int> &s){
    if(s.empty()==true)
        return ;
    int temp=s.top();
    s.pop();
    sort(s);
    insertSort(s,temp);
}
void insertSort(stack<int> &s,int e)
{
    if(s.empty()==true||e<s.top())
    {
        s.push(e);
    }
    else{
        int temp=s.top();
        s.pop();
        insertSort(s,e);
        s.push(temp);
    }
}
void Print(stack<int> &s)
{
    while(s.empty()==false)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(13);
    s.push(5);
    s.push(4);
    s.push(9);
    s.push(2);
    sort(s);
    Print(s);

}