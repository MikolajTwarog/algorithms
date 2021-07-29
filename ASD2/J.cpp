#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

struct odc {
    long long x;
    long long y;
    long long l;
    long long co;
};

odc tab[200010];
int m, n;

bool por(odc a, odc b) {
    if (a.x == b.x) {
        return a.co < b.co;
    }
    return a.x < b.x;
}

bool zamiatanie(long long k) {
    vector<odc> v;
    for (int i = 0; i < n + m; i++) {
        odc a;
        a.l = tab[i].l - k;
        a.x = tab[i].x;
        a.y = tab[i].y;
        if (tab[i].co == 1) {
            a.co = 1;
            if (a.l - k >= 0) {
                a.y += k;
                a.l -= k;
                v.push_back(a);
            }
        } else {
            if (a.l - k >= 0) {
                a.co = 0;
                a.x += k;
                a.l -= k;
                v.push_back(a);
                a.co = 2;
                a.x = a.x + a.l;
                v.push_back(a);
            }
        }
    }
    sort(v.begin(), v.begin() + v.size(), por);
    /*for(int i=0; i<v.size(); i++)
            printf("%lld ", v[i].co);
    printf("\n%d\n", v.size());*/
    set<long long> s;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].co == 0)
            s.insert(v[i].y);
        if (v[i].co == 2)
            s.erase(v[i].y);
        if (v[i].co == 1) {
            set<long long>::iterator q = s.lower_bound(v[i].y);
            if (q != s.end() && *q <= v[i].y + v[i].l)
                return true;
        }
    }
    return false;
}

long long bin(long long n) {
    long long p = 0;
    long long q;
    while (p < n) {
        q = (p + n + 1) / 2;
        if (zamiatanie(q))
            p = q;
        else
            n = q - 1;
    }
    return n;
}

int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        scanf("%d%d", &n, &m);
        long long mx;
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld%lld", &tab[i].x, &tab[i].y, &tab[i].l);
            tab[i].co = 1;
            mx = max(mx, tab[i].l);
        }
        for (int i = n; i < n + m; i++) {
            scanf("%lld%lld%lld", &tab[i].x, &tab[i].y, &tab[i].l);
            tab[i].co = 0;
            mx = max(mx, tab[i].l);
        }
        long long wyn = bin(mx);
        if (wyn < 0)
            wyn = 0;
        printf("%lld\n", wyn);
    }
    return 0;
}
