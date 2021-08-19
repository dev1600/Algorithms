#include<bits/stdc++.h>
using namespace std;

int Partition(int*,int,int ,int );
void QuickSort(int arr[],int low,int high)
{
    if(low>=high)
        return ;
    int pi=arr[high];
    int pivot=Partition(arr,low,high,pi);
    QuickSort(arr,low,pivot-1);
    QuickSort(arr,pivot+1,high);
}
int Partition(int arr[],int low,int high,int pi)
{
    int i=low;
    int j=low;
    while(i<=high)
    {
        if(arr[i]<=pi)
        {
            swap(arr[i],arr[j]);
            i++;
            j++;
            cout<<"swapping "<<arr[i]<<" "<<arr[j]<<endl;
        }
        else {
            i++;
        }
    }
    return j-1;
}
int main(){

    int arr[15];
    int n;
    cout<<"Enter no of elements\t";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}