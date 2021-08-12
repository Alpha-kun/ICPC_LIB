#include<bits/stdc++.h>

using namespace std;

int biSearch(vector<int>& b, int up, int i) {
    if (i > b[up]) return up + 1;
    int lo = 1,hi = up, mid;
    while (lo + 1 < hi) {
        mid = (lo + hi) >>1;
        if (i < b[mid]) hi = mid;
        else lo = mid;
    }
    if (b[lo] < i) return lo + 1;
    else return lo;
}

int lis(vector<int>& arr) {
    int maxL = 0;
    // B[l]: the minimal end for a increasing subsequence that has length l
    vector<int> B(arr.size() + 1,0);
    for (int i = 0; i < arr.size(); i++) {
        int p = biSearch(B, maxL, arr[i]);
        B[p] = arr[i];
        maxL = max(maxL, p);
    }
    return maxL;
}