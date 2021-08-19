#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Time Complexity is nlog(n)
//Constraints - 1<=arr[i]<=n size of array=n+1
int BinarySearch(vector<int> &v,int l,int h)
{
    /*logic used is that we initially binary search(or find middle) an element from [1,2,3..n]
    then we use that value to count elements greater & less than mid in given array */
    int mid=(h+l)/2;
    int greater=0;
    int lesser=0;
    int duplicate;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>mid)
        {
            greater++;
        }
        else if(v[i]<mid)
        {
            lesser++;
        }
    }
    /*If the count of elements is greater than n-mid then repeating element is greater than mid
    similar logic applied for lesser.Ex-[1,2,3,4,5,5] is given and mid is 3 no of elements greater=3
    no of elements less=2 ideally if elements were non repeating(1,2,3,4,5) then greater=2 lesser=2
    hence since actual greater > ideal case hence repeating element is greater than mid=3 */
    if(greater>(v.size()-mid-1))
        duplicate=BinarySearch(v,mid+1,h);
    else if(lesser>mid-1)
        duplicate=BinarySearch(v,l,mid-1);
    else return mid;
    return duplicate;
}
int findDuplicate(vector<int> & v)
{
    int duplicate=BinarySearch(v,1,v.size()-1);
    return duplicate;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {   cin>>x;
        v.push_back(x);
    }
    //cout<<v.size()<<endl;
    int duplicate=findDuplicate(v);
    cout<<"Duplicate = "<<duplicate<<endl;
}