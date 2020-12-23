#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

const int  N     =  5e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n;

struct pt{
    long long x, y;
    pt(){}
    pt(long long _x, long long _y):x(_x), y(_y){}
    pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt & p) const { return x * p.y - y * p.x; }
    long long dot(const pt & p) const { return x * p.x + y * p.y; }
    long long cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

bool onSegment(pt p, pt q, pt r){ 
	if (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && 
		r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y)) 
		return true; 
	return false; 
} 

bool colinear(pt p, pt q, pt r){ 
	ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	return (val == 0);
}

bool InTriangle(pt a, pt b, pt c, pt point){
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}

bool InPolygon(vector<pt> q, vector<pt> p){
	int ok = 0;
	for(auto it : p){
		for(int i = 0; i < q.size(); i++){
			if(colinear(q[i], q[(i+1)%q.size()], it)){
				ok |= onSegment(q[i], q[(i+1)%q.size()], it);
			}
		}
	}
	if(ok) return 0;
	for(auto it : p){
		for(int i = 1; i < q.size()-1; i++){
			ok |= InTriangle(q[0], q[i], q[i+1], it);
		}
	}
	return ok;
}


void solve(){
	cin >> n;
	vector <pt> poly[n+1];
	for(int i = 1; i <= n; i++){
		int vi; cin >> vi;
		for(int j = 1; j <= vi; j++){
			ll x, y; cin >> x >> y;
			poly[i].pb({x, y});
		}
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}