#include<iostream>
#include<algorithm>
using namespace std;

void shellSort(int arr[],int n,int gap)
{
    while(gap!=0)
    {   int j=0;
        while(j<gap)
        { 
            for(int i=j+gap;i<n;i=i+gap)
            {
                int l=i-gap;
                int temp=arr[i];
                while(temp<arr[l]&&l>=0)
                {
                    arr[l+gap]=arr[l];
                    l=l-gap;

                }
                arr[l+gap]=temp;               
            }
            j++;
       }
       gap=gap/2;
    }
}
int main(){
    int arr[]={2,3,0,6,1,8,4};
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    shellSort(arr,n,n/2);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}