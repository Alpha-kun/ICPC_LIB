#include <bits/stdc++.h>

using namespace std;

#define INF 10000001
typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {
    int v, w, cap, cost, f;

    Edge(int a, int b, int c, int d) : v(a), w(b), cap(c), cost(d), f(0) {}

    int other(int s) { return s == v ? w : v; }

    int getRez(int s) {
        if (f > 0) return s == v ? cap - f : f;
        else if (f < 0) return s == v ? -f : cap + f;
        else return cap;
    }

    int getCost(int s) {
        if (f > 0) return s == v ? cost : -cost;
        else if (f < 0) return s == v ? -cost : cost;
        else return cost;
    }

    void addFlow(int s, int d) {
        if (s == v) f += d;
        else f -= d;
    }
};

int n;
vector<Edge *> G[1005];
vector<int> dist;
vector<int> from;
vector<Edge *> arc;

void spfa(int s) {
    dist = vector<int>(n, INF);
    from = vector<int>(n, -1);
    arc = vector<Edge *>(n, nullptr);
    vector<bool> inq(n, false);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (Edge *uv:G[u]) {
            int v = uv->other(u);
            if (uv->getRez(u) > 0 && dist[u] + uv->getCost(u) < dist[v]) {
                dist[v] = dist[u] + uv->getCost(u);
                from[v] = u;
                arc[v] = uv;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

pll MCMF(int s, int t, int p) {
    ll maxflow = 0, mincost = 0;
    while (true) {
        spfa(s);
        if (dist[t] == INF) break;
        //find bottleneck flow
        int flow = INF, cur = t;
        while (cur != s) {
            int pre = from[cur];
            flow = min(flow, arc[cur]->getRez(pre));
            cur = pre;
        }
        //add flow
        cur = t;
        while (cur != s) {
            int pre = from[cur];
            arc[cur]->addFlow(pre, flow);
            cur = pre;
        }
        maxflow += flow;
        mincost += flow * dist[t];
        if (maxflow>=p) break;
    }
    return make_pair(maxflow, mincost);
}