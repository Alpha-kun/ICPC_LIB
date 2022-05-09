//evaluate dp[i][jl...jr] such that kl<=opt(i,j)<=kr for jl<=j<=jr
void dac(int i, int jl, int jr, int kl, int kr) {
    int jmid = (jl + jr) >> 1;
    dp[i][jmid] = INF;
    if (i >= jmid) {
        dp[i][jmid] = 0;
        if (jl <= jmid - 1) {
            dac(i, jl, jmid - 1, kl, kr);
        }
        if (jmid + 1 <= jr) {
            dac(i, jmid + 1, jr, jmid - 1, kr);
        }
    } else {
        int optk = kl;
        for (int k = kl; k <= min(kr, jmid - 1); ++k) {
            if (dp[i - 1][k] + cost(k + 1, jmid) < dp[i][jmid]) {
                dp[i][jmid] = dp[i - 1][k] + cost(k + 1, jmid);
                optk = k;
            }
        }
        if (jl <= jmid - 1) {
            dac(i, jl, jmid - 1, kl, optk);
        }
        if (jmid + 1 <= jr) {
            dac(i, jmid + 1, jr, optk, kr);
        }
    }
}

//compute base case
for (int i = 1; i <= n; ++i) {
    dp[1][i] = cost(1, i);
}

for (int i = 2; i <= k; ++i) {
    dac(i, 1, n, 0, n - 1);
}