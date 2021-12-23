int n;//=2* # of variables
vector<int> g[MAXN], gt[MAXN];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u: g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u: gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

//add clause a==av|b==bv
void add(int a, int av, int b, int bv) {
    //a!=av ==> b==bv
    g[2 * a + av].push_back(2 * b + (1 ^ bv));
    //b!=bv ==> a==av
    g[2 * b + bv].push_back(2 * a + (1 ^ av));
    //in reverse graph
    gt[2 * b + (1 ^ bv)].push_back(2 * a + av);
    gt[2 * a + (1 ^ av)].push_back(2 * b + bv);
}