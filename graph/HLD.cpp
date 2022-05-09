vector<int> G[MAXN];/**WARNING: G will be modified**/
int sz[MAXN];
int depth[MAXN];
int pa[MAXN];
int chr[MAXN];
int place[MAXN];
int EDGE_MODE = 0;/**WARNING: if using edge mode, watch out for l>r segtree query**/

void dfs(int u, int p) {
    sz[u] = 1;
    depth[u] = p == -1 ? 0 : depth[p] + 1;
    pa[u] = p;
    //delete parent
    if (p != -1)
        G[u].erase(find(G[u].begin(), G[u].end(), p));/**WARNING: delete this line if G is given with pnt->chd only**/

    for (int v: G[u]) {
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
    while (chr[u] != chr[v]) {
        // Always pull up the chain with the deeper root.
        if (depth[chr[u]] > depth[chr[v]]) swap(u, v);
        int root = chr[v];
        add(rt, place[root], place[v], x);
        v = pa[root];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    // u is now an ancestor of v.
    add(rt, place[u] + EDGE_MODE, place[v], x);
}

int query(int u, int v) {
    int ans = 0;
    while (chr[u] != chr[v]) {
        // Always pull up the chain with the deeper root.
        if (depth[chr[u]] > depth[chr[v]]) swap(u, v);
        int root = chr[v];
        ans = ans + find_sum(rt, place[root], place[v]);
        v = pa[root];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    // u is now an ancestor of v.
    /**u is the LCA of the two inputs**/
    ans = ans + find_sum(rt, place[u] + EDGE_MODE, place[v]);
    return ans;
}

//dfs(0, -1);
//chain_dfs(0, false);
//rt = new Node(0, n + 1);