#include<bits/stdc++.h>

using namespace std;

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct sparse_table {
    int n, level;
    vector <vector <T>> st;
    T e;
    F f;

    sparse_table() {}
    sparse_table(vector <T> a, int n, T e, F &&f) : n(n), e(e), f(f) {
        level = log2(n) + 1;
        st.assign(n + 1, vector <int> (level, -1));

        for (int j = 0; j < level; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (j == 0) st[i][j] = a[i];
                else st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        T ans = e;
        for (int j = level - 1; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans = f(ans, st[l][j]);
                l += 1 << j;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    // vector of values(1 indexed), no of values, identity element of the function, function
    sparse_table<int> st(vector <int> (n + 1, 0), n, 0, [&](const int &a, const int &b) {
        return a + b;
    });
}