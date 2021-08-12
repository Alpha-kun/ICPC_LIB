#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define INF 1000000009

struct Edge {
    int v, w, cap, f;
    Edge(int a, int b, int c) : v(a), w(b), cap(c), f(0) {}
    int other(int s) { return s == v ? w : v; }
    int getRez(int s) { return s == v ? cap - f : f; }
    void addFlow(int s, int d) {
        if (s == v) f += d;
        else f -= d;
    }
};

bool marked[MAXN];
vector<Edge*> graph[MAXN];

int dfs(int s, int t, int f) {
    if (s == t) return f;
    marked[s] = true;
    for (Edge *edge : graph[s]) {
        int to = edge->other(s);
        if (!marked[to] && edge->getRez(s) > 0) {
            int d = dfs(to, t, min(f, edge->getRez(s)));
            if (d > 0) {
                edge->addFlow(s, d);
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    int totalFlow = 0;
    while (true) {
        memset(marked, false, sizeof(marked));
        int inc = dfs(s, t, INF);
        if (inc == 0) break;
        totalFlow += inc;
    }
    return totalFlow;
}