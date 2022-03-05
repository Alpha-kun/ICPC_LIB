int adj[100][100];

vector<int> ans;

void euler(int u) {
    for (int v = 0; v < 10; ++v) {
        if (adj[u][v]) {
            adj[u][v] = adj[v][u] = 0;
            euler(v);
        }
    }
    ans.push_back(u);
}

//WARNING: modifies the adj array
//WARNING: only call when an euler path or tour exist
//WARNING: when only euler path exists, call at the source node