#define MOD 1000000000051L


ll mult(ll a, ll b) {
    ll bl = b >> 20;
    ll br = b & ((1<<20)-1);
    ll p1 = (a * bl) % MOD;
    p1 = (p1<<20) % MOD;
    ll p2 = (a * br) % MOD;
    return (p1 + p2) % MOD;
}