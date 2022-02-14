#define LEN 320

//for 1-index array
vector<int> bin(n + 1);
for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    bin[i] = i / LEN;
}

vector<int> L(n / LEN + 1), R(n / LEN + 1);
for (int i = 0; i <= n / LEN; ++i) {
    L[i] = max(1, i * LEN);
    R[i] = min((i + 1) * LEN - 1, n);
    if (R[i] == n) break;
}