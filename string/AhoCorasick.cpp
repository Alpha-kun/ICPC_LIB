#define idx(c) c-'a'

vector<vector<int>> ch;
vector<int> val;
vector<int> f;
vector<int> last;

void insert(string &s, int id) {
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (ch[n][idx(s[i])] == 0) {
            ch.push_back(vector<int>(26, 0));
            val.push_back(0);
            ch[n][idx(s[i])] = ch.size() - 1;
        }
        n = ch[n][idx(s[i])];
        if (i == s.size() - 1) {
            val[n] = id;
        }
    }
}

void buildtrie(vector<string> &p) {
    //WARNING: p must be vector of DISTINCT strings
    ch.push_back(vector<int>(26, 0));
    val.push_back(0);
    for (int i = 0; i < p.size(); ++i) {
        insert(p[i], i + 1);
    }
}

void getFail() {
    queue<int> q;
    f = vector<int>(ch.size(), 0);
    last = vector<int>(ch.size(), 0);
    for (int c = 0; c < 26; ++c) {
        if (ch[0][c]) q.push(ch[0][c]);
    }
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        for (int c = 0; c < 26; ++c) {
            int u = ch[r][c];
            if (!u) continue;
            q.push(u);
            int v = f[r];
            while (v > 0 && ch[v][c] == 0) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
}

void collect(int i, int j) {
    if (j) {
        printf("at char %d, trie node %d, match string %d\n", i, j, val[j]);        
        collect(i, last[j]);
    }
}

void findall(string &T) {
    int n = T.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int c = idx(T[i]);
        while (j > 0 && ch[j][c] == 0) j = f[j];
        j = ch[j][c];
        if (val[j]) collect(i, j);
        else if (last[j]) collect(i, last[j]);
    }
}