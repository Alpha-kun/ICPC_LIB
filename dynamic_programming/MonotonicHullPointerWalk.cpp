#define INF 10000000000.0

vector<ll> M;
vector<ll> B;

bool bad(int l1, int l2, int l3) {
    return (B[l3] - B[l1]) * (M[l1] - M[l2]) < (B[l2] - B[l1]) * (M[l1] - M[l3]);
}

//query need to be given in non-decreasing m
void add(ll m, ll b) {
    M.push_back(m);
    B.push_back(b);
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
    }
}

int pointer = 0;

//query need to be given in non-decreasing x
ll query(ll x) {
    if (pointer >= M.size())
        pointer = M.size() - 1;
    while (pointer < M.size() - 1 &&
           M[pointer + 1] * x + B[pointer + 1] > M[pointer] * x + B[pointer])
        pointer++;
    return M[pointer] * x + B[pointer];
}

//no restriction on query order
ll eval(ll x) {
    int lo = 0, hi = M.size() - 1, mid;
    while (lo + 1 < hi) {
        mid = (lo + hi) >> 1;
        if (x * M[mid - 1] + B[mid - 1] > x * M[mid] + B[mid]) hi = mid;
        else if (x * M[mid] + B[mid] < x * M[mid + 1] + B[mid + 1]) lo = mid;
        else return x * M[mid] + B[mid];
    }
    return max(x * M[lo] + B[lo], x * M[hi] + B[hi]);
}