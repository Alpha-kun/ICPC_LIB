using namespace std;
typedef pair<double, pair<int, int>> pdii;

int p[MAXN];
int sz[MAXN];

int root(int i) {
    return p[i] == i ? i : root(p[i]);
}

void uni(int u, int v) {
    if (sz[root(u)] <= sz[root(v)]) {
        sz[root(v)] += sz[root(u)];
        p[root(u)] = root(v);
    } else {
        sz[root(u)] += sz[root(v)];
        p[root(v)] = root(u);
    }
}

int x[MAXN];
int y[MAXN];
int r[MAXN];

int main() {

    for (int i = 0; i < MAXN; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
    
    priority_queue<pdii, vector<pdii>, greater<pdii>> pq;
    //add edges
	
    double leng = 0;
    int edge = 0;
    while (!pq.empty()) {
        pdii pr = pq.top();
        pq.pop();
        int u = pr.second.first;
        int v = pr.second.second;
        if (root(u) == root(v)) continue;
        uni(u, v);
        edge++;
        leng += pr.first;
        if (edge == n - 1) break;
    }
    printf("%.7f",leng);
    return 0;
}