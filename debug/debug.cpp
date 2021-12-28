#define watch(x) cout << (#x) << " is " << (x) << endl

void show(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < v.size(); ++i) cout << setw(4) << v[i];
    cout << endl;
}