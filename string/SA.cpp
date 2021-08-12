#include <bits/stdc++.h>

using namespace std;

vector<int> getSA(string &str) {
    int n = str.length();
    int m = 200;
    vector<int> r(n << 1, 0);
    for (int i = 0; i < n; i++) r[i] = str[i];
    for (int k = 1; k < n; k <<= 1) {
        // radix sort the second key
        vector<int> count(m, 0);
        vector<int> aux0(n, 0);
        for (int i = 0; i < n; i++) count[r[i + k]]++;
        for (int i = 1; i < m; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) aux0[--count[r[i + k]]] = i;
        // radix sort the first key
        count = vector<int>(m, 0);
        vector<int> aux1(n, 0);
        for (int i = 0; i < n; i++) count[r[aux0[i]]]++;
        for (int i = 1; i < m; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) aux1[--count[r[aux0[i]]]] = aux0[i];
        // count repetition
        vector<int> rank1(n << 1, 0);
        int p = 1;
        rank1[aux1[0]] = p;
        for (int i = 1; i < n; i++)
            rank1[aux1[i]] = r[aux1[i - 1]] == r[aux1[i]] && r[aux1[i - 1] + k] == r[aux1[i] + k] ? p : ++p;
        // wrap up this iteration
        r = rank1;
        if (p >= n) break;
        m = p + 1;
    }
    vector<int> sa(n, 0);
    for (int i = 0; i < n; i++) sa[r[i] - 1] = i;
    return sa;
}

string T = "ababcadababca";
//The ith the smallest suffix starts at sa[i]
vector<int> sa = getSA(T);
//rank[i] is the rank of the ith suffix in T
//height[i] is the length of LPC between sa[i-1], sa[i]
int rnk[MAXN], height[MAXN];

void getHeight() {
    int k = 0, n = T.size();
    for (int i = 0; i < n; ++i) rnk[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (k) k--;
        int j = sa[rnk[i] - 1];
        while (max(i + k, j + k) < T.size() && T[i + k] == T[j + k]) k++;
        height[rnk[i]] = k;
    }
}
