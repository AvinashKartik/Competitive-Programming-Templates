#include<bits/stdc++.h>

using namespace std;

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct segment_tree {
	int n;
	std::vector<T> tree;
	T e;
	F f;

	segment_tree() {}

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F &&f): n(n), tree(4 * n), e(e), f(f) {
		build(v, 1, 1, n);
	}

	template<typename U>
	void build(const std::vector<U> &v, int node, int start, int end) {
		if (start == end) {
			tree[node] = T(v[start]);
		} else {
			int mid = (start + end) / 2;
			build(v, 2 * node, start, mid);
			build(v, 2 * node + 1, mid + 1, end);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	void pushlazy(int start, int end, int node) {
		if (tree[node].lazy == 0) return;

		tree[node].val = (end - start + 1) * tree[node].lazy;

		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	template<typename U>
	void update(int l, int r, U val) {
		update_helper(1, 1, n, l, r, val);
	}

	template<typename U>
	void update_helper(int node, int start, int end, int l, int r, U val) {
		pushlazy(start, end, node);
		if (start > end || start > r || end < l)
			return;
		if (start >= l && end <= r) {
			tree[node].lazy += val;
			pushlazy(start, end, node);
		} else {
			int mid = (start + end) / 2;
			update_helper(node * 2, start, mid, l, r, val);
			update_helper(node * 2 + 1, mid + 1, end, l, r, val);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	T query(int l, int r) {
		return query_helper(1, 1, n, l, r);
	}

	T query_helper (int node, int start, int end, int l, int r) {
		if (start > end || start > r || end < l)
			return e;
		pushlazy(start, end, node);
		if (l <= start && end <= r)
			return tree[node];
		int mid = (start + end) / 2;
		T p1 = query_helper(2 * node, start, mid, l, r);
		T p2 = query_helper(2 * node + 1, mid + 1, end, l, r);
		return f(p1, p2);
	}
};

struct node {
	int val, lazy;
	node(): val(0), lazy(0) {}
	node(int v): val(v), lazy(0) {}
};

int main() {
	int n;
	cin >> n;
	// vector of values(1 indexed), no of values, identity element of the function, function
	segment_tree<node> st(vector <int>(n + 1, 0), n, node(), [&](const node & a, const node & b) {
		node c;
		c.val = a.val + b.val;
		return c;
	});
}
