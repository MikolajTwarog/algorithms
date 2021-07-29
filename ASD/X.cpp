#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int source = 26 * 26 + 1;

struct edge {
    int a, b, w;
};

// vector<pair<int, int>> g[26 * 26 + 10];
vector<edge> edges;
float dist[26 * 26 + 10];
int n;

bool bellman(float x) {
    dist[source] = 0;
    for (int i = 0; i < source; i++)
        dist[i] = 1000000000;

    for (int i = 0; i <= n; i++) {
        for (edge e : edges) {
            dist[e.b] = min(dist[e.b], dist[e.a] + (x - e.w));
        }
    }
    for (edge e : edges) {
        if (dist[e.b] > dist[e.a] + (x - e.w)) {
            return true;
        }
    }

    return false;
}

float bin(float begin, float end) {
    if (end - begin < 0.000099)
        return begin;

    if (bellman((end + begin) / 2))
        return bin((begin + end) / 2, end);
    else
        return bin(begin, (begin + end) / 2);
}

int trans(char a, char b) { return 26 * (a - 'a') + (b - 'a'); }

int main() {
    ios_base::sync_with_stdio(false);

    int z;
    cin >> z;
    while (z--) {
        cin >> n;

        float mx = 0, mn = INT_MAX;

        for (int i = 0; i < source; i++) {
            edge a;
            a.a = source;
            a.b = i;
            a.w = 0;
            edges.push_back(a);
        }

        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            int temp = a.length();

            edge x;
            x.a = trans(a[0], a[1]);
            x.b = trans(a[temp - 2], a[temp - 1]);
            x.w = temp;
            edges.push_back(x);

            // x.a = source;
            // x.w = 0;
            // edges.push_back(x);

            // x.b = trans(a[0], a[1]);
            // edges.push_back(x);

            mx = max((float)temp, mx);
            mn = min((float)temp, mn);
        }

        if (!bellman(0))
            cout << "NIE\n";
        else
            cout << fixed << setprecision(4) << bin(mn - 1, mx + 1) << endl;

        edges.clear();
    }
}