#include<bits/stdc++.h>

using namespace std;

struct union_find {
	int n, components;
	vector <int> p, sz;

	union_find() {}
	union_find(int n) : n(n), components(n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		sz.assign(n + 1, 1);
	}

	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}

	void merge(int x, int y) {
		int a = find(x);
		int b = find(y);
		if (a != b) {
			if (sz[a] >= sz[b]) swap(a, b);
			p[a] = b;
			sz[b] += sz[a];
			components--;
		}
	}
};

int main() {
	int n;
	cin >> n;
	// no of nodes
	union_find dsu(n);
}