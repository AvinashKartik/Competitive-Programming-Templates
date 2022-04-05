#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct bitwise_trie {
	int n, b;
	stack <int> s;
	vector <T> trie;

	bitwise_trie() {}
	bitwise_trie(int n, int b) : n(n), b(b) {
		for (int i = n - 1; i >= 1; i--) s.push(i);
		trie.resize(n);
	}

	void insert(int x) {
		int v = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			if (trie[v].go[k] == -1) {
				trie[v].go[k] = s.top();
				s.pop();
			}
			trie[v].cnt++;
			v = trie[v].go[k];
		}
		trie[v].cnt++;
	}

	void erase(int x) {
		int v = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			trie[v].cnt--;
			int tmp = trie[v].go[k];
			if (trie[tmp].cnt == 1) {
				s.push(tmp);
				trie[v].go[k] = -1;
			}
			v = tmp;
		}
		trie[v].cnt--;
	}

	int min_xor(int x, int f = 0) {
		int v = 0, ans = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			if (trie[v].go[k ^ f] != -1) {
				ans += (1 << i) * f;
				v = trie[v].go[k ^ f];
			} else {
				ans += (1 << i) * (1 ^ f);
				v = trie[v].go[k ^ 1 ^ f];
			}
		}
		return ans;
	}

	int max_xor(int x) {
		return min_xor(x, 1);
	}
};

struct node {
	vector <int> go = { -1, -1};
	int cnt = 0;
};

int main() {
	int n;
	cin >> n;
	// (no of bits + 1) * n, no. of bits
	bitwise_trie <node> t(31 * n, 30);
}
