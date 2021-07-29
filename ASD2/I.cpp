#include <bits/stdc++.h>
using namespace std;

struct circle {
    long long x, y, r, i;
};

struct endpoint {
    long long x;
    circle cir;
    bool left;
    endpoint() {}
    endpoint(long long x, circle cir, bool left) : x(x), cir(cir), left(left) {}
    bool operator<(endpoint b) { return x < b.x; }
};

bool separate(circle a, circle b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) >
           (a.r + b.r) * (a.r + b.r);
}

struct cut {
    circle cir;
    bool up;
    cut() {}
    cut(circle cir, bool up) : cir(cir), up(up) {}
};

bool operator<(cut a, cut b) {
    if (a.cir.i == b.cir.i)
        return a.up < b.up;
    if (separate(a.cir, b.cir)) {
        return a.cir.y < b.cir.y;
    }
    if (a.cir.r < b.cir.r) {
        if (b.up)
            return true;
        return false;
    }
    if (a.up)
        return false;
    return true;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        long long n;
        cin >> n;
        // circle circles[n];
        endpoint points[2 * n];
        for (long long i = 0; i < n; ++i) {
            circle c;
            cin >> c.x >> c.y >> c.r;
            c.i = i + 1;
            points[2 * i] = endpoint(c.x - c.r, c, true);
            points[2 * i + 1] = endpoint(c.x + c.r, c, false);
        }

        sort(points, points + 2 * n);
        long long parent[n];
        set<cut> s;

        for (long long i = 0; i < 2 * n; ++i) {
            cut cut_up = cut(points[i].cir, true);
            cut cut_down = cut(points[i].cir, false);
            if (points[i].left) {
                set<cut>::iterator it = s.lower_bound(cut_up);
                if (it == s.end())
                    parent[cut_up.cir.i] = 0;
                else {
                    if ((*it).up)
                        parent[cut_up.cir.i] = (*it).cir.i;
                    else
                        parent[cut_up.cir.i] = parent[(*it).cir.i];
                }
                s.insert(cut_up);
                s.insert(cut_down);
            } else {
                s.erase(cut_up);
                s.erase(cut_down);
            }
        }

        for (long long i = 1; i <= n; i++) {
            cout << parent[i] << endl;
        }
    }
}