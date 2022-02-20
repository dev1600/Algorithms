// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int left, int right, int k) {
        //code here
        int i=left;
        int j=left;
        //Swapping pivot element with last element
        swap(arr[(left+right)/2],arr[right]);
        int pivot=arr[right];
        while(j<right){
            if(arr[j]<pivot){
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
        swap(arr[j],arr[i]);
        if(i+1==k){
            return pivot;
        }
        else if(i+1<k)
        {
            return kthSmallest(arr,i+1,right,k);
        }
        else {
            return kthSmallest(arr,left,i-1,k);
        }
   
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cout<<"Enter No. of test cases"<<endl;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends