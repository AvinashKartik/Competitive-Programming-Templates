#include<bits/stdc++.h>

using namespace std;

struct diGraph {
	int n, m, is_cyclic;
	vector <int> v, w, topological_sort;
	vector <vector <int>> adj, rev;

	diGraph() {}
	diGraph(int n) : n(n), m(0), is_cyclic(-1) {
		adj.resize(n + 1, vector <int>());
		rev.resize(n + 1, vector <int>());
	}

	void add_edge(int ui, int vi, int wi = 0) {
		v.push_back(vi);
		w.push_back(wi);
		adj[ui].push_back(m++);

		v.push_back(ui);
		w.push_back(wi);
		rev[vi].push_back(m++);
	}

	bool check_cyclic() {
		is_cyclic = 0;

		vector <int> d(n + 1, 0);
		queue <int> q;

		for (int i = 1; i <= n; i++) {
			for (auto it : adj[i]) d[v[it]]++;
		}

		for (int i = 1; i <= n; i++) if (!d[i]) q.push(i);

		while (q.size()) {
			int x = q.front();
			q.pop();
			topological_sort.push_back(x);

			for (auto i : adj[x]) {
				d[v[i]]--;
				if (d[v[i]] == 0) q.push(v[i]);
			}
		}

		if (topological_sort.size() != n) {
			is_cyclic = 1;
			topological_sort.clear();
		}

		return is_cyclic;
	}

	void scc_helper1(int x, vector <int> &vis, vector <int> &order) {
		vis[x] = 1;
		for (auto i : adj[x]) {
			if (vis[v[i]]) continue;
			scc_helper1(v[i], vis, order);
		}
		order.push_back(x);
	}

	void scc_helper2(int x, vector <int> &vis, vector <int> &component) {
		vis[x] = 1;
		component.push_back(x);
		for (auto i : rev[x]) {
			if (vis[v[i]]) continue;
			scc_helper2(v[i], vis, component);
		}
	}

	vector <vector <int>> scc() {
		vector <int> order, component;
		vector <int> vis(n + 1, 0);
		vector <vector <int>> components;

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) scc_helper1(i, vis, order);
		}

		vis.assign(n + 1, 0);
		reverse(order.begin(), order.end());
		for (auto i : order) {
			if (!vis[i]) {
				component.clear();
				scc_helper2(i, vis, component);
				components.push_back(component);
			}
		}

		return components;
	}

};

int main() {
	int n;
	cin >> n;
	// no of nodes
	diGraph g(n);
}