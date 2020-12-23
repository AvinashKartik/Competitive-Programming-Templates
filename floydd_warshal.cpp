#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll adj[305][305], path[305][305];
ll n,m,u,v,d,l,q,ct,st,end1;
int flag;
ll MAX = 1e18;

int main(){
	cin>>n>>m>>l;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j)continue;
			adj[i][j] = MAX;
		}
	}

	for(ll i = 0; i<m; i++){
		cin>>u>>v>>d;
		if(d <= l){
			adj[u][v] = d;
			adj[v][u] = d;
			path[u][v] = u;
			path[v][u] = v;
		}
	}
	//cout<<1;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=n; k++){
				if(adj[j][k] > adj[j][i] + adj[i][k]){
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j) continue;
			adj[i][j] = (adj[i][j] <= l)? 1 : MAX; 
		}
	}

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=n; k++){
				if(adj[j][k] > adj[j][i] + adj[i][k]){
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}

	cin>>q;
	for(int i = 1; i<=q; i++){
		cin>>u>>v;
		if(adj[u][v] == MAX)
			cout<<-1<<endl;
		else
			cout<<adj[u][v]-1<<endl;
	}
	
}