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

void dijkstra(graph &g, int s = 1) {
    int n = g.n;
    vector <long long> d(n + 1, LLONG_MAX), p(n + 1, -1);

    d[s] = 0;
    set <pair <long long, int>> q;
    q.insert({0, s});

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto i : g.adj[v]) {
            int to = g.v[i];
            long long len = g.w[i];
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    // no of nodes
    graph g(n);
    // graph, root
    dijkstra(g, n, 1);
}
