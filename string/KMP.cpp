vector<int> getFail(string &p) {
    int m = p.size();
    vector<int> f(m + 1);
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j > 0 & p[i] != p[j]) j = f[j];
        f[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
    return f;
}

void findall(string &T, string &p) {
    int n = T.size(), m = p.size();
    int j = 0;
    vector<int> f = getFail(p);
    for (int i = 0; i < n; ++i) {
        while (j > 0 && (j == m || T[i] != p[j])) j = f[j];
        if (T[i] == p[j]) j++;
        if (j == m) printf("%d ", i - m + 1);
    }
    printf("\n");
}