#include <bits/stdc++.h>

#define MAXN 10000
using namespace std;

struct Edge {
    int a, b, cut;

    Edge(int u, int v, int b) : a(u), b(v), cut(b) {}

    int other(int x) { return x == a ? b : a; }
};


vector<Edge *> g[MAXN];
int dfsn[MAXN] = {0};
int low[MAXN] = {0};
bool ap[MAXN] = {false};
int cont = 0;

//visiting v from u a.k.a. u->v
void dfs(int v, int u, Edge *uv) {
    low[v] = dfsn[v] = ++cont;
    int child = 0;
    for (Edge *vw:g[v]) {
        int w = vw->other(v);
        if (!dfsn[w]) {
            child++;
            dfs(w, v, vw);
            low[v] = min(low[v], low[w]);
            if (dfsn[v] <= low[w]) ap[v] = true;
        } else {
            if (w != u) low[v] = min(low[v], dfsn[w]);
        }
    }
    if (u < 0 && child == 1) ap[v] = false;
    if (low[v] >= dfsn[v]) uv->cut = 1;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<Edge *> edge;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        Edge *e = new Edge(u, v, 0);
        g[u].push_back(e);
        g[v].push_back(e);
        edge.push_back(e);
    }
    return 0;
}
