int a[MAXN+1];

int query(int x) {
     int sum = 0;
     for (; x; x -= x&-x) sum += a[x];
     return sum;
}

void update (int x, int v) {
     for(; x<=MAXN; x += x&-x) a[x] += v;
}
