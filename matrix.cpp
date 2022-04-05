#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct matrix {
	vector <vector <T>> mat;
	int n, m;

	matrix(): mat(), n(), m() {}
	matrix(vector <vector <T>> v): mat(v), n(v.size()), m(v[0].size()) {}

	matrix operator *(matrix b) {
		vector <vector <T>> v(n, vector <T>(m, 0));
		matrix res(v);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					res.mat[i][j] += mat[i][k] * b.mat[k][j];
				}
			}
		}
		return res;
	}

	void print() {
		for (auto row : mat) {
			for (auto col : row) cout << col << " ";
			cout << "\n";
		}
	}

	matrix pow(long long y, int n) {
		vector <vector <int>> v(n, vector <int>(n, 0));
		for (int i = 0; i < n; i++) v[i][i] = 1;
		matrix res(v), x(*this);
		while (y) {
			if (y & 1) res = res * x;
			x = x * x;
			y /= 2;
		}
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector <vector <int>> v(n, vector <int>(n, 1));
	matrix a(v);
}