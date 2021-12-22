#include<bits/stdc++.h>

using namespace std;

struct Node {
    Node *lc, *rc;
    int l, r, data;

    Node(int lb, int rb){
        l=lb,r=rb;
        data = 0;
        if (lb == rb) {
            lc = rc = nullptr;
        } else {
            int mid = (lb + rb) / 2;
            lc = new Node(lb, mid);
            rc = new Node(mid + 1, rb);
        }
    }
};

void pd(Node *n) {
    if (n->l == n->r) return;
    if (n->reset!=-1) {
        n->lc->reset = n->rc->reset = n->reset;
        n->reset = -1;
    }
}

void update(Node *n, int x, int val) {
    if (n->l == n->r)
        n->reset = val;
    else {
        int mid = (n->l + n->r) / 2;
        pd(n);
        if (x <= mid) sit(n->lc, x, val);
        else sit(n->rc, x, val);
    }
}

int git(Node *n, int x) {
    if (n->l == n->r)
        return n->reset;
    else {
        int mid = (n->l + n->r) / 2;
        pd(n);
        if (x <= mid) return git(n->lc, x);
        else return git(n->rc, x);
    }
}

void del(Node *n) {
    if (n->l == n->r) {
        delete n;
        return;
    }
    del(n->lc);
    del(n->rc);
    delete n;
}