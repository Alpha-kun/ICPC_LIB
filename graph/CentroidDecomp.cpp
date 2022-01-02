set<int> tree[MAXN]; // it's not vector<vector<int>>!
int dad[MAXN];
int sz[MAXN];
map<int, int> dist[MAXN];

//find subtree size
int dfsz(int u, int p) {
    sz[u] = 1;
    for (int v: tree[u])
        if (v != p) sz[u] += dfsz(v, u);
    return sz[u];
}

//find centroid
int dfsc(int u, int p, int n) {
    for (int v: tree[u])
        if (v != p && sz[v] > n / 2) return dfsc(v, u, n);
    return u;
}

// find dist(c,u)
void dfsd(int c, int u, int p, int d) {
    dist[c][u] = d;
    for (auto v: tree[u])
        if (v != p) dfsd(c, v, u, d + 1);
}

//call build(0,-1) in main
void build(int u, int p) {
    int n = dfsz(u, p); // find the size of each subtree
    int centroid = dfsc(u, p, n); // find the centroid
    if (p == -1) p = centroid; // dad of root is the root itself
    dad[centroid] = p;
    dfsd(centroid, centroid, -1, 0);
    // for each tree resulting from the removal of the centroid
    vector<int> nbr;
    for (int v: tree[centroid]) nbr.push_back(v);
    for (int v: nbr) {
        tree[centroid].erase(v); // remove the edge to disconnect
        tree[v].erase(centroid); // the component from the tree
        build(v, centroid);
    }
}