#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  20;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll t=1,dp[20][10][2],sz,K;
string l,r,dig;

ll rec(ll ind, ll k, int f){
    if(ind == sz){
        return 1;
    }
    if(dp[ind][k][f] != -1) return dp[ind][k][f];
    dp[ind][k][f] = 0;
    int d = r[ind]-'0';
    for(int i = 0; i <= 9; i++){
        if(f == 1 and i > d) break;
        if(i < k) continue;
        dp[ind][k][f] += rec(ind+1,i,f&(d==i));
    }
    return dp[ind][k][f];
}

ll solve(){
    mset(dp,-1);
    cin>>r;
    sz = r.size();
    deb1(rec(0,0,1)-1);
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}