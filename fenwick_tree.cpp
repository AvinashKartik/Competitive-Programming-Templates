#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct fenwick_tree {
	int n;
	vector <T> tree;

	fenwick_tree() {}
	fenwick_tree(int n, T val) : n(n + 2) {
		tree.assign(n + 2, val);
	}

	template<typename U>
	void update(int idx, U val) {
		idx++;
		while (idx < n) {
			tree[idx] += val;
			idx += idx & (-idx);
		}
	}

	T query(int idx) {
		idx++;
		T ans = 0;
		while (idx > 0) {
			ans += tree[idx];
			idx -= idx & (-idx);
		}
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	// no of values, data type (usually long long or int)
	fenwick_tree f(n, 0ll);
}