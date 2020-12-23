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

const int  N     =  3e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, q, msk[N], ans[N];
vll adj[N];
string s[N];

int bfs(int s, int f){
	vector <int> dist(n + 1, -1);
	queue <int> q;
	dist[s] = 1;
	q.push(s);
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto it : adj[x]){
			if(dist[it] == -1){
				dist[it] = dist[x] + 1;
				q.push(it);
			}
		}
	}
	return dist[f];
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++) adj[i].clear(), msk[i] = 0, ans[i] = -1;
	vector <vector<int>> ct(n + 1, vector<int>(26, 0));
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		for(auto it : s[i]){
			ct[i][it - 'A']++;
		}
		for(int k = 0; k < 26; k++){
			if(ct[i][k]) msk[i] += (1ll << k);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ll f = msk[i] & msk[j];
			if(f) adj[i].pb(j);
		}
	}
	for(int i = 1; i <= q; i++){
		int s, f; cin >> s >> f;
		adj[s].pb({f, i});
	}
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}