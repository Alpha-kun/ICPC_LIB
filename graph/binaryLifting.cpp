int n, m;

vector<pii> T[MAXN];
int up[MAXN][20];
int dep[MAXN];
int maxi[MAXN][20];

//populate up[u][0], maxi[u][0], dep
void init(int u, int pnt, int w) {
    up[u][0] = pnt;
    maxi[u][0] = w;
    dep[u] = pnt == -1 ? 0 : dep[pnt] + 1;
    for (pii vw: T[u]) {
        if (vw.first != pnt) init(vw.first, u, vw.second);
    }
}

//populate up, maxi
void preprocess() {
    for (int i = 1; i < 20; ++i) {
        for (int u = 1; u <= n; ++u) {
            up[u][i] = up[up[u][i - 1]][i - 1];
            maxi[u][i] = max(maxi[u][i - 1], maxi[up[u][i - 1]][i - 1]);
        }
    }
}

//find the hth ancestor of u
int lift(int &u, int h) {
    int w = 0;
    for (int i = 0; i < 20; ++i) {
        if (u != -1) if (h & (1 << i)) w = max(w, maxi[u][i]), u = up[u][i];
    }
    return w;
}

int pathMax(int u, int v) {
    int w = lift(u, dep[u] - min(dep[u], dep[v]));
    w = max(w, lift(v, dep[v] - min(dep[u], dep[v])));
    if (u == v) return w;
    for (int i = 19; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            w = max(w, maxi[u][i]);
            w = max(w, maxi[v][i]);
            u = up[u][i], v = up[v][i];
        }
    }
    return max(w, max(maxi[u][0], maxi[v][0]));
}