#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first               
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, m, k;

void solve(){
	cin >> n >> m >> k;
	vector <int> r(m + 1, n + 1), c(n + 1, m + 1);
	for(int i = 1; i <= k; i++){
		int x, y; cin >> x >> y;
		r[x] = min(r[x], y);
		c[y] = min(c[y], x);
	}
	ll ans = 1;
	vector <int> v;
	for(int i = 2; i < r[1]; i++){
		ans += c[i] - 1;
	}
	vpll u;
	for(int i = 2; i < c[1]; i++){
		ans += r[i] - 1;
		u.pb({r[i] - 1, i})
	}
	sort(all(u));
	int j = 1;
	for(auto it : u){

		ans -= upper_bound(all(v), r[i] - 1) - v.begin();
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	ll test = 1;
	//cin >> test;
	for(ll i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}