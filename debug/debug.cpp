#include "assert.h"
#define watch(x) cout << (#x) << " is " << (x) << endl
void show(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < v.size(); ++i) cout << setw(4) << v[i];
    cout << endl;
}

//0xC0000374 heap corruption
//0xC0000005 invalid memory access
//0xC00000FD stackoverflow
//0xC0000094 divide by zero
