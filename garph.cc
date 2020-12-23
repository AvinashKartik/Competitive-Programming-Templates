#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  

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

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, p[5][2], v[25][4];

// ll calc(pll p1, pll p2, pll p3, pll p4){
// 	if(p1.f == p2.f){
// 		ll d = abs(p1.s - p2.s);
// 		ll dist1 = abs(p3.s - p1.s) + abs(p4.s - p2.s) + abs(p1.f + d - p3.f) + abs(p2.f + d - p4.f);
// 		ll dist2 = abs(p3.s - p1.s) + abs(p4.s - p2.s) + abs(p1.f - d - p3.f) + abs(p2.f - d - p4.f);
// 		return min(dist1, dist2); 
// 	} else {
// 		ll d = abs(p1.f - p2.f);
// 		ll dist1 = abs(p3.f - p1.f) + abs(p4.f - p2.f) + abs(p1.s + d - p3.s) + abs(p2.s + d - p4.s);
// 		ll dist2 = abs(p3.f - p1.f) + abs(p4.f - p2.f) + abs(p1.s - d - p3.s) + abs(p2.s - d - p4.s);
// 		//deb3(d, dist1, dist2)
// 		return min(dist1, dist2); 
// 	}
// }

// ll f1(int i, int j, int k, int l){
// 	pll p1, p2, p3, p4;
// 	p1 = {p[i][0], p[i][1]};
// 	p2 = {p[i][0], p[j][1]};
// 	p3 = {p[k][0], p[k][1]};
// 	p4 = {p[l][0], p[l][1]};
// 	ll ans1 = min(calc(p1, p2, p3, p4), calc(p1, p2, p4, p3)) + abs(p[i][0] - p[j][0]);
// 	p2 = {p[j][0], p[i][1]};
// 	ll ans2 = min(calc(p1, p2, p3, p4), calc(p1, p2, p4, p3)) + abs(p[i][1] - p[j][1]);
// 	return min(ans1, ans2);
// }

ll dist(pll p, pll q){
	return abs(p.f - q.f) + abs(p.s - q.s);
}

ll f(ll d, ll x, ll y){
	pll p1, p2, p3, p4;
	p1 = {x, y};
	p2 = {x + d, y};
	p3 = {x, y + d};
	p4 = {x + d, y + d};
	ll res = INF;
	for(int i = 0; i < 24; i++){
		ll ans = 0;
		ans += dist({p[v[i][0]][0], p[v[i][0]][1]}, p1);
		ans += dist({p[v[i][1]][0], p[v[i][1]][1]}, p2);
		ans += dist({p[v[i][2]][0], p[v[i][2]][1]}, p3);
		ans += dist({p[v[i][3]][0], p[v[i][3]][1]}, p4);
		res = min(res, ans);
	}
	return res;
}

ll ts3(ll d, ll x) {
	ll l = 0, r = 1e9;
    while(r - l > 2){
    	ll m1 = l + (r - l) / 3;
    	ll m2 = r - (r - l) / 3;
    	ll f1 = f(d, x, m1);
    	ll f2 = f(d, x, m2);
    	if (f1 > f2) l = m1;
		else r = m2;
    }
    ll ans = f(d, x, l);
    for(int i = l; i <= r; i++) ans = min(ans, f(d, x, i));
}

ll ts2(ll d) {
	ll l = 0, r = 1e9;
    while(r - l > 2){
    	ll m1 = l + (r - l) / 3;
    	ll m2 = r - (r - l) / 3;
    	ll f1 = ts3(d, m1);
    	ll f2 = ts3(d, m2);
    	if (f1 > f2) l = m1;
		else r = m2;
    }
    ll ans = ts3(d, l);
    for(int i = l; i <= r; i++) ans = min(ans, ts3(d, i));
}

ll ts() {
	ll l = 0, r = 1e9;
    while(r - l > 2){
    	ll m1 = l + (r - l) / 3;
    	ll m2 = r - (r - l) / 3;
    	ll f1 = ts2(m1);
    	ll f2 = ts2(m2);
    	if (f1 > f2) l = m1;
		else r = m2;
    }
    ll ans = ts2(l);
    for(int i = l; i <= r; i++) ans = min(ans, ts2(i));
}

void solve(){
	for(int i = 1; i <= 4; i++){
		cin >> p[i][0] >> p[i][1];
	}
	ll ans = INF;
	// for(int i = 1; i <= 4; i++){
	// 	for(int j = 1; j <= 4; j++){
	// 		if(i == j) continue;
	// 		set <int> s;
	// 		for(int k = 1; k <= 4; k++) s.insert(k);
	// 		s.erase(i);
	// 		s.erase(j);
	// 		int p3 = *s.begin();
	// 		int p4 = *s.rbegin();
	// 		ans = min(ans, f1(i, j, p3, p4));
	// 		//deb3(i, j, ans)
	// 	}
	// }
	ans = ts();
	deb1(ans)
}

int main(){
	GODSPEED;
	vll u(4);
	iota(all(u), 1);
	int ct = 0;
	do{
		for(int i = 0; i < 4; i++) v[ct][i] = u[i];
		ct++;
	} while(next_permutation(all(u)));
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}