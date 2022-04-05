#include<bits/stdc++.h>

using namespace std;

struct graph {
    int n, m;
    vector <int> v, w;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
};

struct ancestors {
    int n, level, root;
    vector <vector <int>> st;
    graph g;
    vector <int> p, d;

    ancestors() {}
    ancestors(graph &g, int r) : n(g.n), g(g), root(r) {
        level = log2(n) + 1;
        st.assign(n + 1, vector <int> (level, -1));
        p.assign(n + 1, 0);
        d.assign(n + 1, 0);
        fillst();
    }

    void findpar(int x, int par) {
        p[x] = par;
        for (auto it : g.adj[x]) {
            if (g.v[it] == par) continue;
            d[g.v[it]] = d[x] + 1;
            findpar(g.v[it], x);
        }
    }

    void fillst() {
        findpar(root, 0);
        for (int j = 0; j < level; j++) {
            for (int i = 1; i <= n; i++) {
                if (j == 0) st[i][j] = p[i];
                else if (st[i][j - 1] != -1) st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }
    }

    int kth(int x, int k) {
        for (int i = level - 1; i >= 0; i--) {
            if (k >= (1 << i)) {
                x = st[x][i];
                k -= (1 << i);
            }
        }
        return x;
    }

    int lca(int x, int y) {
        if (d[y] < d[x]) swap(x, y);
        y = kth(y, d[y] - d[x]);
        if (x == y) return x;

        for (int i = level - 1; i >= 0; i--) {
            if (st[x][i] != -1 && st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }
        return st[x][0];
    }

    int distance(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }
};

int main() {
    int n;
    cin >> n;
    // no of nodes
    graph g(n);
    // graph, root
    ancestors lca(g, 1);
}