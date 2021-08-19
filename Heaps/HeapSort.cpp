#include<iostream>
#include<algorithm>
using namespace std;

void Heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(arr[l]>arr[largest]&&l<n)
        largest=l;
    if(arr[r]>arr[largest]&&r<n)
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}

void Display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
int main(){
    int arr[]={2,1,5,3,9,4};
    int size=sizeof(arr)/sizeof(int);
    //Since leaf nodes already follow heap property we start from last parent node
    for(int i=size/2-1;i>=0;i--)
    {
        Heapify(arr,size,i);
    }
    //We replace max with last and heapify to find right pos of last element
    for(int i=size-1;i>=0;i--)
    {
        swap(arr[i],arr[0]);
        Heapify(arr,i,0);
    }
    Display(arr,size);

}