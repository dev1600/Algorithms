#include <bits/stdc++.h>
using namespace std;

priority_queue<int>maxHeap;
priority_queue<int,vector<int>,greater<int>>minHeap;
void insertHeap(int &x)
{
        int l_size=maxHeap.size();
        int r_size=minHeap.size();
        if(l_size==0)
            maxHeap.push(x);
            //below condition means atleast one element will be inserted into maxHeap
        else if(l_size==r_size){
            if(minHeap.top()>x)
            {
                maxHeap.push(x);
            }
            else {
                int t=minHeap.top();
                minHeap.pop();
                minHeap.push(x);
                maxHeap.push(t);
            }
            
        }
        //below condition means we odd no of elements hence have to equalise
        else {
            if(r_size==0)
            {
                if(x>maxHeap.top())
                {
                    minHeap.push(x);
                }
                else{
                    int t=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(t);
                    maxHeap.push(x);
                }
            }
            else if(minHeap.top()<=x)
            {
                minHeap.push(x);
            }
            else{
                if(x<maxHeap.top())
                {
                    int t=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(t);
                    maxHeap.push(x);
                }
                else minHeap.push(x);
            }
        }
}
double getMedian()
{
        if((maxHeap.size()+minHeap.size())%2==0)
        {
            return (double(maxHeap.top())+double(minHeap.top()))/2.0;
        }
        else return maxHeap.top();
        
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        insertHeap(a);
        cout<<"Median->"<<getMedian()<<endl;

    }
    return 0;
}