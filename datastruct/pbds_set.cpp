#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> treap;

int main() {
    treap T;
    T.insert(5);
    T.insert(2);
    T.insert(8);
    T.insert(3);
        
    //order_of_key(x) if x is added to T, what index would it have
    cout << T.order_of_key(3) << endl;//1
    cout << T.order_of_key(7) << endl;//3
    cout << T.order_of_key(9) << endl;//4

    //find_by_order(i) return the ith element
    cout << *T.find_by_order(0) << endl;//2
    cout << *T.find_by_order(1) << endl;//3
    cout << (T.end() == T.find_by_order(4)) << endl;//1
    return 0;
}
