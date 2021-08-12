//adding a series of lines f_i(x)=ax+b with decreasing a, given x, find minimum f_i(x) in O(logN)
#include<bits/stdc++.h>

using namespace std;
#define INF 10000000000

int n = -1;
vector<pair<int, int>> line;
vector<pair<double, double>> interval;

double intersect(pair<int, int> p, pair<int, int> q) {
    return 1.0 * (q.second - p.second) / (p.first - q.first);
}

void add(pair<int, int> nl) {
    if (n == -1) {
        line.push_back(nl);
        interval.push_back(make_pair(-INF, INF));
        n++;
        return;
    }
    if (n == 0) {
        line.push_back(nl);
        interval[0] = make_pair(-INF, intersect(line[0], line[1]));
        interval.push_back(make_pair(intersect(line[0], line[1]), INF));
        n++;
        return;
    }
    while (line.size() >= 2) {
        if (intersect(line[n - 1], nl) <= intersect(line[n - 1], line[n])) {
            line.pop_back();
            interval.pop_back();
            n--;
        } else {
            break;
        }
    }
    interval[n] = make_pair(interval[n].first, intersect(line[n], nl));
    interval.push_back(make_pair(intersect(line[n], nl), INF));
    line.push_back(nl);
    n++;
}

int eval(int x) {
    int lo = 0, hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (x < interval[mid].first)
            hi = mid;
        else if (interval[mid].second < x)
            lo = mid;
        else
            return line[mid].first * x + line[mid].second;
    }
    if (interval[lo].first <= x && x <= interval[lo].second)
        return line[lo].first * x + line[lo].second;
    else
        return line[hi].first * x + line[hi].second;
}