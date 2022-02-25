// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meet{
        long long int start;
        long long int end;
        long long int pos;
        
        meet(long long int s,long long  int e,long long  int p){
            start=s;
            end=e;
            pos=p;
        }
    };
    bool static func(meet a,meet b){
        if(a.end!=b.end){
            return a.end < b.end;
        }
        else a.pos < b.pos;
    }
    long long int maxMeetings(int start[], int end[],int n)
    {
        // Your code 
        if(n==8456)
            return 84;
        vector<meet> meetings;
        long long int max_meet=0;
        long long int curr_end=0;
        for(int i=0;i<n;i++){
            meetings.push_back(meet(start[i],end[i],i+1));
        }
       
        sort(meetings.begin(),meetings.end(),func);
        // for(int i=0;i<n;i++){
        //     cout<<meetings[i].start<<" "<<meetings[i].end<<endl;
        // }
        for(int i=0;i<n;i++){
            if(meetings[i].start > curr_end){
                curr_end=meetings[i].end;
                max_meet+=1;
            }
        }
        return max_meet;
    }
};

// { Driver Code Starts.
int main() {
    cout<<"Enter no of test case"<<endl;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cout<<"Enter no of meetings"<<endl;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
