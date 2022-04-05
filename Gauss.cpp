#include<bits/stdc++.h>

using namespace std;

struct gauss {
	int b, size;
	vector <int> basis;

	gauss() {}
	gauss(int b) : b(b), size(0) {
		basis.assign(b + 1, 0);
	}

	void insert(long long x) {
		for (int i = b; i >= 0; i--) {
			if (((x >> i) & 1) == 0) continue;
			if (!basis[i]) {
				basis[i] = x;
				size++;
				break;
			} else x ^= basis[i];
		}
	}

	bool is_part(long long x) {
		for (int i = b; i >= 0; i--) {
			if (((x >> i) & 1) == 0) continue;
			x ^= basis[i];
		}
		return x == 0;
	}

	vector <int> get_elements() {
		vector <int> v = {0};
		for (int i = 0; i <= b; i++) {
			if (basis[i] == 0) continue;
			int sz = v.size();
			for (int j = 0; j < sz; j++) v.push_back(v[j] ^ basis[i]);
		}
		return v;
	}
};

int main() {
	int b;
	cin >> b;
	// no of bits
	gauss g(b);
}