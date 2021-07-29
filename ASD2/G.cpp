#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct point {
    ll x, y, z;
    point() {}
    point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

struct plane {
    ll A, B, C, D;
    plane(point a, point b, point c) {
        A = (b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y);
        B = (b.z - a.z) * (c.x - a.x) - (b.x - a.x) * (c.z - a.z);
        C = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        D = getD(a);
    }
    ll getD(point a) { return (-1) * (A * a.x + B * a.y + C * a.z); }
};

bool check_if_wall(plane pl, point *vertices, int n) {
    ll exp = 0;
    for (ll i = 0; i < n; i++) {
        ll curr = pl.D - pl.getD(vertices[i]);
        if (exp == 0)
            exp = curr;
        else if ((curr > 0 && exp < 0) || (curr < 0 && exp > 0))
            return false;
    }
    return true;
}

double distance(plane pl, point m) {
    return abs(pl.A * m.x + pl.B * m.y + pl.C * m.z + pl.D) /
           sqrt(pow(pl.A, 2) + pow(pl.B, 2) + pow(pl.C, 2));
}

int main() {
    ll z;
    cin >> z;
    while (z--) {
        point m;
        cin >> m.x >> m.y >> m.z;

        ll n;
        cin >> n;
        point vertices[n + 1];
        for (ll i = 0; i < n; i++)
            cin >> vertices[i].x >> vertices[i].y >> vertices[i].z;

        double result = INT32_MAX;

        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                for (ll k = j + 1; k < n; k++) {
                    plane pl(vertices[i], vertices[j], vertices[k]);
                    if (check_if_wall(pl, vertices, n)) {
                        result = min(result, distance(pl, m));
                        // cout << i << " " << j << " " << k << "\n";
                    }
                }
            }
        }

        cout << std::fixed << std::setprecision(15) << result << "\n";
    }
}
