#define LEN 600

struct query {
    int l, r, id;

    query(int L, int R, int K, int ID) : l(L), r(R), k(K), id(ID) {}
	
	bool operator<(query o) const {
        return make_pair(l/LEN, r) < make_pair(o.l/LEN, o.r);
    }
};

sort(Q.begin(), Q.end());

int lb = 0, rb = -1;
for (Query q : queries) {
    while (lb > q.l) {
        lb--;
        add(lb);
    }
    while (rb < q.r) {
        rb++;
        add(rb);
    }
    while (lb < q.l) {
        remove(lb);
        lb++;
    }
    while (rb > q.r) {
        remove(rb);
        rb--;
    }
    answers[q.idx] = get_answer();
}