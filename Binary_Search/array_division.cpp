#include<bits/stdc++.h>
using namespace std;
bool solver(vector<long long int> arr,long long int n,long long int mw){
    long long int sum=0,ans=1;
    for(auto i:arr){
        if(sum + i <= mw) sum+=i;
        else{
            sum=i;
            ans++;
        }
    }
    return ans<=n;
}
long long int findAns(vector<long long int > &arr, long long int k) {
    long long int n = arr.size();
    if(k>n) return -1;
    long long int maxi = INT_MIN,sum=0;
    for(auto i:arr){
        sum+=i;
        maxi = max(maxi,i);
    }
    if(k==1) return sum;
    //if(k==n) return maxi;
    long long int l=maxi,r=sum;
    while(l<=r){
        long long int mid = (l+r)>>1;
        if(solver(arr,k,mid))   r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int> v(n);
    for(long long int i=0;i<n;i++) cin>>v[i];
    cout<<findAns(v,k);
}