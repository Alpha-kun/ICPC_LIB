struct RMQ {
    vector<vector<ll>> jmp;

    RMQ(const vector<ll> &V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
            jmp.emplace_back(((int) V.size()) - pw * 2 + 1);
            for (int j = 0; j < jmp[k].size(); j++)
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }

    //rmq.query(inclusive, exclusive);
    ll query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};