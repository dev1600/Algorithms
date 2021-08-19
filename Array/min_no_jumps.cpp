 #include<iostream>
 #include<algorithm>
 using namespace std;
 
 
 int minJumps(int arr[], int n){
        //if no of elements <=1 no steps required
        if(n<=1)
        {
            return -1;
        }
        //if first element is 0 then cant jump
        if(arr[0]==0)
        {
            return -1;
        }
        //min no of jumps required is 0
        int jumps=1;
        int i=1;
        int steps=arr[0];//steps required
        int max_reach=arr[0];//max reach of steps
        for(i=1;i<n;i++)
        {
            if(i==n-1)
            {
                return jumps;
            }
            max_reach=max(max_reach,arr[i]+i);
            steps--;
            if(steps==0)
            {
                jumps++;
                if(i>=max_reach)
                    return -1;
                    
                steps=max_reach-i;//steps = max possible index reach - current index
            }
         
        }
        return -1;
 }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int jumps=minJumps(arr,n);
    cout<<"Jumps= "<<jumps<<endl;
}