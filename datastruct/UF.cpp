int p[MAXN];
int sz[MAXN];
int cont;

int root(int i) {
    return p[i] == i ? i : root(p[i]);
    //with path compression
    //return p[i] = p[i] == i ? i : root(p[i]);
}

void uni(int u, int v) {
    if (sz[root(u)] <= sz[root(v)]) {
        sz[root(v)]+=sz[root(u)];
        p[root(u)] = root(v);
    } else {
        sz[root(u)]+=sz[root(v)];
        p[root(v)] = root(u);
    }
}

//iota(p, p + MAXN, 0);
//fill_n(sz, MAXN, 1);