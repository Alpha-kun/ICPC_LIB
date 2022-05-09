//A is a 0-1 matrix
int maxZeroSubmatrix(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    //u[i][j]: how long can a line extend up from (i,j)
    int u[n][m];
    for (int j = 0; j < m; ++j) {
        u[0][j] = 1 - A[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 1) u[i][j] = 0;
            else if (A[i - 1][j] == 1) u[i][j] = 1;
            else u[i][j] = 1 + u[i - 1][j];
        }
    }
    //l[i][j]: the leftmost index the u[i][j] line can be extended to
    int l[n][m];
    for (int i = 0; i < n; ++i) {
        vector<int> stk;
        for (int j = 0; j < m; ++j) {
            while (!stk.empty() && u[i][j] <= u[i][stk.back()]) stk.pop_back();
            if (stk.empty()) l[i][j] = 0;
            else l[i][j] = stk.back() + 1;
            stk.push_back(j);
        }
    }
    //r[i][j]: the rightmost index the u[i][j] line can be extended to
    int r[n][m];
    for (int i = 0; i < n; ++i) {
        vector<int> stk;
        for (int j = m - 1; j >= 0; --j) {
            while (!stk.empty() && u[i][j] <= u[i][stk.back()]) stk.pop_back();
            if (stk.empty()) r[i][j] = m - 1;
            else r[i][j] = stk.back() - 1;
            stk.push_back(j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans = max(ans, u[i][j] * (r[i][j] - l[i][j] + 1));
    return ans;
}