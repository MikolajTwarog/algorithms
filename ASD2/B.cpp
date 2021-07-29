#include <bits/stdc++.h>
using namespace std;

struct edge {
    int end;
    int cap;
    int reverse;

    edge(int end, int cap, int reverse)
        : end(end), cap(cap), reverse(reverse) {}
};

vector<edge> g[16010];

int make_flow(int s, int t, int *prev, int mn) {
    // for (int i = 0; i < 10; i++)
    //     cout << g[i][prev[i]].end << " ";
    int v = t;
    v = t;
    while (v != s) {
        // if (prev[v] == -1)
        //     return -1;
        // cout << v;
        g[g[v][prev[v]].end][g[v][prev[v]].reverse].cap -= mn;
        g[v][prev[v]].cap += mn;
        v = g[v][prev[v]].end;
    }

    return mn;
}

int bfs(int s, int t, int n) {
    queue<int> q;
    q.push(s);
    int prev[2 * n + 1];
    int minw[2 * n + 1];
    for (int i = 0; i < 2 * n; i++) {
        prev[i] = -1;
        minw[i] = INT32_MAX;
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // cout << v << "\n";
        if (v == t) {
            return make_flow(s, t, prev, minw[t]);
        }
        for (int i = 0; i < g[v].size(); i++) {
            if (g[v][i].cap > 0 && prev[g[v][i].end] == -1) {
                q.push(g[v][i].end);
                prev[g[v][i].end] = g[v][i].reverse;
                minw[g[v][i].end] = min(minw[v], g[v][i].cap);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        if (prev[i] > -1 && prev[n + i] == -1)
            res++;

    cout << res << "\n";
    for (int i = 0; i < n; i++)
        if (prev[i] > -1 && prev[n + i] == -1)
            cout << i + 1 << " ";
    // cout << g[i][prev[i]].end << " " << g[i + n][prev[i + n]].end <<
    //"\n";
    if (res > 0)
        cout << "\n";

    return -1;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        s--;
        t--;

        for (int i = 0; i < n; i++) {
            g[i].push_back(edge(n + i, 1, 0));
            g[n + i].push_back(edge(i, 0, 0));
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[n + a].push_back(edge(b, INT32_MAX, g[b].size()));
            g[b].push_back(edge(n + a, 0, g[n + a].size() - 1));
            g[n + b].push_back(edge(a, INT32_MAX, g[a].size()));
            g[a].push_back(edge(n + b, 0, g[n + b].size() - 1));
        }

        // for (int i = 0; i < 2 * n; i++) {
        //     cout << i << "\n";
        //     for (int j = 0; j < g[i].size(); j++)
        //         cout << g[i][j].end << " ";
        //     cout << "\n";
        // }

        while (true) {
            int temp = bfs(n + s, t, n);
            // cout << temp << " ";
            if (temp < 0)
                break;
        }

        for (int i = 0; i < 2 * n; i++)
            g[i].clear();
    }
}