vector<int> G[MAXN];//WILL BE MODIFIED!!!!!!
int sz[MAXN];
int depth[MAXN];
int pa[MAXN];
int chr[MAXN];
int place[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    depth[u] = p == -1 ? 0 : depth[p] + 1;
    pa[u] = p;
    //delete parent
    if (p != -1)
        G[u].erase(find(G[u].begin(), G[u].end(), p));

    for (int v:G[u]) {
        dfs(v, u);
        sz[u] += sz[v];
    }
    //sort the heaviest child first
    sort(G[u].begin(), G[u].end(), [&](int a, int b) {
        return sz[a] > sz[b];
    });
}

int dfsn = 0;

void chain_dfs(int u, bool hvy) {
    place[u] = ++dfsn;
    chr[u] = hvy ? chr[pa[u]] : u;
    for (int i = 0; i < G[u].size(); ++i) {
        chain_dfs(G[u][i], i == 0);
    }
}


void update(int u, int v, int x) {
//    printf("update %d-%d with %d\n", u, v, x);
    while (chr[u] != chr[v]) {
        // Always pull up the chain with the deeper root.
        if (depth[chr[u]] > depth[chr[v]]) swap(u, v);
        int root = chr[v];
        segtree.add(place[root], place[v], x);
//        printf("process1 %d-%d\n", place[root], place[v]);
        v = pa[root];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    // u is now an ancestor of v.
    segtree.add(place[u], place[v], x);
//    printf("process2 %d-%d\n", place[u], place[v]);
}

int query(int u, int v) {
    int ans = 0;
    while (chr[u] != chr[v]) {
        // Always pull up the chain with the deeper root.
        if (depth[chr[u]] > depth[chr[v]]) swap(u, v);
        int root = chr[v];
        ans = segtree.max(find_max(rt, place[root], place[v]));
        v = pa[root];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    // u is now an ancestor of v.
        ans = segtree.max(find_max(rt, place[u], place[v]));
    return ans;
}