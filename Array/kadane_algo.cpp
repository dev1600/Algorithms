#include<iostream>
#include<algorithm>
#include<climits> //this is header file for INT_MIN & INT_MAX
using namespace std;

//This is a dynamic problem apporoach ,watch video to understand better*/
int maxSubarraySum(int arr[], int n){
        
        
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
          
      if((sum+arr[i])>arr[i])
            sum+=arr[i];//either we add the no. to the subsequence
    else 
            sum=arr[i];//or we start a new subsequence from this no
    
      if(max_sum<sum)//if current sum of subsequence is > max sum of subsequence then we swap
            max_sum=sum;
        
      }
    return max_sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int max=maxSubarraySum(arr,n);
    cout<<"max= "<<max<<endl;    

}