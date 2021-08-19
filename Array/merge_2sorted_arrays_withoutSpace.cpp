#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    	    // code here
    int i=0,j=0,k=n-1;
    /*here we run a loop and swap arr2 elements with arr1 if arr1[i]>arr2[j]  hence after loop
    arr1 contains shortest n elemtns between arr1 and arr2*/
   while(i<=k&&j<m)
   {
       if(arr1[i]>arr2[j])
        swap(arr1[k--],arr2[j++]);
       else {
           i++;
       }
   }
   sort(arr1,arr1+n);
   sort(arr2,arr2+m);
	    
}
int main(){
    int arr1[]={1,2,3,4};
    int arr2[]={5,6,7,8,9,10};
    merge(arr1,arr2,4,6);
    for(int i=0;i<4;i++)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<6;i++)
    {
        cout<<arr2[i]<<" ";
    }


}