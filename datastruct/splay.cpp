#include<bits/stdc++.h>

#define sz(o) (o!=nullptr? o->s: 0)
using namespace std;

struct Node {
    Node *ch[2];
    int v, s;

    Node(int val) : v(val) {
        ch[0] = ch[1] = nullptr;
        s = 1;
    }

    void maintain() {
        s = 1 + sz(ch[0]) + sz(ch[1]);
    }
};

void rotate(Node *&o, int d) {
    Node *k = o->ch[d ^ 1];
    o->ch[d ^ 1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void splay(Node *&o, int k) {
    int d = (k < sz(o->ch[0]) + 1 ? 0 : 1);
    if (k != sz(o->ch[0]) + 1) {
        Node *p = o->ch[d];
        int rnkp = d * (sz(o->ch[0]) + 1) + sz(p->ch[0]) + 1;
        if (k != rnkp) {
            int d2 = (k < rnkp ? 0 : 1);
            int k2 = (d2 == 0 ? k : k - sz(p->ch[0]) - 1);
            splay(p->ch[d2], k2);
            if (d == d2) rotate(o, d ^ 1);
            else rotate(o->ch[d], d);
        }
        rotate(o, d ^ 1);
    }
}

void show(Node *o) {
    if (o->ch[0] != nullptr) show(o->ch[0]);
    cout << o->v << ':' << sz(o) << endl;
    if (o->ch[1] != nullptr) show(o->ch[1]);
}

Node *rt;

void insert(int val, int k) {
    if (k == 1) {
        splay(rt, 1);
        rt->ch[0] = new Node(val);
        rt->maintain();
    } else if (k == sz(rt) + 1) {
        splay(rt, sz(rt));
        rt->ch[1] = new Node(val);
        rt->maintain();
    } else {
        splay(rt, k - 1);
        Node *l = rt;
        Node *r = l->ch[1];
        l->ch[1] = new Node(val);
        l->maintain();
        splay(l, k);
        l->ch[1] = r;
        rt = l;
        rt->maintain();
    }
}