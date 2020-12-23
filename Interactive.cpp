#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
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
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N];

void q(int i, int i1, int j1, int j){
	ll d1, d2, d3, d4;
	cout << "Q ";
	deb4(i, i1, i, i1)
	cin >> d1;
	cout << "Q ";
	deb4(j1, j, j1, j)
	cin >> d2;
	cout << "Q ";
	deb4(i, i1, j1, j)
	cin >> d3;
	cout << "Q ";
	deb4(j1, j, i, i1)
	cin >> d4;
	if(a[i] - a[j] == d3){
		a[i1] = a[i] - d1;
		a[j1] = a[j] + d2;
	} else if(a[j] - a[i] == d4){
		a[i1] = a[i] + d1;
		a[j1] = a[j] - d2;
	} else if(a[i] - (a[j] - d2) == d3){
		a[i1] = a[i] - d1;
		a[j1] = a[j] - d2;
	} else {
		a[i1] = a[i] + d1;
		a[j1] = a[j] + d2;
	}
}

void print(){
	cout << "! ";
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
 
void solve(){
	mset(a, -1);
	cin >> n >> a[1] >> a[n];
	int i = 1, j = n;
	while(i + 1 != j){
		q(i, i + 1, j - 1, j);
		i++, j--;
	}
	print();
}

int main(){
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}