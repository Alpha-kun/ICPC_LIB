#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ret[0]: gcd(a,b)
// ret[1]: x in x*a + y*b = gcd(a,b)
// ret[2]: y in x*a + y*b = gcd(a,b)
// specially, if gcd(a,b) = 1
// x*a mod b = 1, y*b mod a = 1


vector<ll> exgcd(ll a, ll b) {
    if (b == 0) {
        vector<ll> ret = vector<ll>({a, 1, 0});
        return ret;
    }
    vector<ll> temp = exgcd(b, a % b);
    vector<ll> ret = vector<ll>({temp[0], temp[2], temp[1] - (a / b) * temp[2]});
    return ret;
}

// greatest common denominator
ll gcd(ll p, ll q) {
    if (q == 0)
        return p;
    return gcd(q, p % q);
}

// compute a table of all multiplicative inverse of p in O(P)
void multinv(int p){
    int inv[p];
    inv[1] = 1;
    for (int i = 2; i < p; i++) {
        inv[i] = p - ((p / i) * inv[p % i] % p);
    }
}