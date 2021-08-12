#include<bits/stdc++.h>

#define sz(o) (o!=nullptr? o->s: 0)
using namespace std;

struct Node {
    Node *ch[2];
    int r, v, s;

    Node(int rk, int val) : r(rk), v(val) {
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

void insert(Node *&o, int x) {
    if (o == nullptr) o = new Node(rand(), x);
    else {
        int d = (x < o->v ? 0 : 1);
        insert(o->ch[d], x);
        if (o->ch[d]->r > o->r) rotate(o, d ^ 1);
        else o->maintain();
    }
}

void remove(Node *&o, int x) {
    if (x == o->v) {
        if (o->ch[0] == nullptr) o = o->ch[1];
        else if (o->ch[1] == nullptr) o = o->ch[0];
        else {
            int d = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
            rotate(o, d);
            remove(o->ch[d], x);
        }
    } else remove(o->ch[x < o->v ? 0 : 1], x);
    o->maintain();
}

bool has(Node *o, int x) {
    if (o == nullptr) return 0;
    if (x == o->v) return 1;
    else if (x < o->v) return has(o->ch[0], x);
    else return has(o->ch[1], x);
}

int rnk(Node *o, int x) {
    if (x == o->v) return sz(o->ch[0]) + 1;
    else if (x < o->v) return rnk(o->ch[0], x);
    else return sz(o->ch[0]) + 1 + rnk(o->ch[1], x);
}

Node *rt = nullptr;

int main() {
    insert(rt, 5);
    insert(rt, 2);
    insert(rt, 9);
    cout<<has(rt,2)<<endl;
    cout<<rnk(rt,5)<<endl;
    insert(rt, 1);
    remove(rt,2);
    cout<<rnk(rt,5)<<endl;
    cout<<rnk(rt,9)<<endl;
    return 0;
}
