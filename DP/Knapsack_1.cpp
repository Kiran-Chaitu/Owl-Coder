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

ll dp[100][(int)(1e5+1)];
ll solver(vector<pair<ll,ll>> &v , ll ind , ll n , ll m) {
    if(ind >= n) return 0;
    if(dp[ind][m]!=-1) return dp[ind][m];
    ll left = 0 , right =0;
    if(m >= v[ind].first){
        left +=(v[ind].second + solver(v,ind+1 , n , m-v[ind].first));
    }
    right = solver(v, ind+1 , n ,m);
    dp[ind][m] = max(left,right);
    return dp[ind][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> v(n);
    memset(dp , -1 ,sizeof(dp));
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        //cout<<v[i].first <<" "<<v[i].second<<endl;
    }
    cout<<solver(v,0 , n , m);

    return 0;
}
