#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
bool fun(vl &v,ll k,ll n,ll mid){
    ll sum=0;
    for(ll i=0;i<n;i++){
        if(sum+(mid/v[i])<0) return true;
        sum+=mid/v[i];
        // cout<<"Sum= "<<sum<<endl;
    }
    // cout<<"EndSum= "<<sum<<endl;
    return sum>=k;
}
void solver() {
    ll n,k,mini=INF,maxi = INT_MIN;
    cin>>n>>k;
    vl v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i] < mini) mini = v[i];
        if(v[i] > maxi) maxi = v[i];
    }
    
    ll l=mini , r = maxi * k;
    while(l<=r){
        ll mid = (l+r)>>1;
        // cout<<"l = "<<l<<" r= "<<r<<endl;
        // cout<<"mid = "<<mid<<endl;
        if(fun(v,k,n,mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solver(); 

    return 0;
}
