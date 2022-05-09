struct Node {
    Node *lc, *rc;
    int l, r, min, lazy;

    Node(int lb, int rb) : l(lb), r(rb) {
        min = lazy = 0;
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
    if (n->lazy != 0) {
        n->lc->min += n->lazy;
        n->rc->min += n->lazy;
        n->lc->lazy += n->lazy;
        n->rc->lazy += n->lazy;
        n->lazy = 0;
    }
}

void pu(Node *n) {
    if (n->l == n->r) return;
    n->min = min(n->lc->min, n->rc->min);
}

void add(Node *n, int l, int r, int val) {
    if (n->l == l && n->r == r) {
        n->min += val;
        n->lazy += val;
        return;
    }
    pd(n);
    int mid = (n->l + n->r) >> 1;
    if (r <= mid) {
        add(n->lc, l, r, val);
    } else if (mid + 1 <= l) {
        add(n->rc, l, r, val);
    } else {
        add(n->lc, l, mid, val);
        add(n->rc, mid + 1, r, val);
    }
    pu(n);
}

int query(Node *n, int l, int r) {
    if (n->l == l && n->r == r) {
        return n->min;
    }
    pd(n);
    int mid = (n->l + n->r) >> 1;
    if (r <= mid) {
        return find_min(n->lc, l, r);
    } else if (mid + 1 <= l) {
        return find_min(n->rc, l, r);
    } else {
        return min(find_min(n->lc, l, mid), find_min(n->rc, mid + 1, r));
    }
}

Node *rt;