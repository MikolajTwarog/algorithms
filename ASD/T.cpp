#include <iostream>
#include <vector>
using namespace std;

vector<int> g[200010];
int pre[200010];
int low[200010];
int tsize[200010];
long long numofpairs[200010];
int rsize[200010];

int t = 1;

void init_tabs(int n, int m) {
    t = 1;

    for (int i = 0; i <= n; i++) {
        g[i].clear();
        pre[i] = -1;
        tsize[i] = 1;
        numofpairs[i] = 0;
        rsize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void dfs(int v, int parent) {
    pre[v] = t++;
    low[v] = pre[v];
    for (int i : g[v]) {
        if (pre[i] == -1) {
            dfs(i, v);
            low[v] = min(low[v], low[i]);
            tsize[v] += tsize[i];
            if (low[i] >= pre[v]) {
                numofpairs[v] +=
                    (long long)tsize[i] * (long long)(tsize[i] - 1);
                rsize[v] += tsize[i];
            }
        } else {
            if (i != parent)
                low[v] = min(low[v], pre[i]);
        }
    }
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        init_tabs(n, m);
        dfs(1, -1);
        // for (int i = 1; i <= n; i++)
        //     cout << i << " pre " << pre[i] << " low " << low[i] << "\n";

        for (int i = 1; i <= n; i++) {
            cout << (long long)(n - 1 - rsize[i]) *
                            (long long)(n - 2 - rsize[i]) +
                        numofpairs[i]
                 << "\n";
        }
    }
}