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
const ll lx = LLONG_MAX;
const ll ln = LLONG_MIN;

// Tabulation

// ll solver(vl &v , ll ind ,ll n ,vl &dp){
//     for(ll i=ind;i<n;i++){
//         ll diff1 = abs(v[i] - v[i-1]) , diff2 = abs(v[i] - v[i-2]);
//         if(diff1+dp[i-1] < diff2+dp[i-2]){
//             dp[i] = diff1 + dp[i-1];
//         }
//         else{
//             dp[i] = diff2 + dp[i-2];
//         }
//         // cout<<dp[i]<<" ";
//     }
//     // cout<<endl;
//     return dp[n-1];
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<ll> dp(1e5+1);   
//     ll n;
//     cin>>n;
//     vl v(n);
//     for(ll i=0;i<n;i++) cin>>v[i];
//     dp[1] =abs(v[1] - v[0]);
//     cout<<solver(v , 2,n ,dp);
//     return 0;
// }

// Recursion

ll solver(vl &v , ll ind ,  vl &dp){
    if(ind<=0){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind]; 
    ll left = lx , right = lx;
    left = abs(v[ind] - v[ind-1]) + solver(v,ind-1,dp);
    if(ind>1)   right = abs(v[ind] - v[ind-2]) + solver(v,ind-2,dp);
    // if(right==0) return left;
    dp[ind] = min(left , right);
    return dp[ind];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> dp(1e5+1,-1);   
    ll n;
    cin>>n;
    vl v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    cout<<solver(v ,n -1,dp);
    return 0;
}
