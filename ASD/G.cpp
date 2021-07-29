#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[200010];
int col[200010];
long long int cost[200010];
long long int wyn[200010][2];
int police[200010];

void dfs(int n) {
    col[n] = 1;
    int a = g[n].size();
    for (int i = 0; i < a; i++) {
        if (col[g[n][i]] == 0) {
            dfs(g[n][i]);
        }
    }
    wyn[n][0] = 0;
    wyn[n][1] = cost[n];
    for (int i = 0; i < a; i++) {
        if (col[g[n][i]] == 2) {
            wyn[n][0] += wyn[g[n][i]][1];
            wyn[n][1] += min(wyn[g[n][i]][1], wyn[g[n][i]][0]);
        }
    }
    col[n] = 2;
}

void dfs2(int v, int czy) {
    police[v] = czy;
    for (int i = 0; i < g[v].size(); i++) {
        if (police[g[v][i]] == -1) {
            if (czy == 0 || wyn[g[v][i]][1] < wyn[g[v][i]][0]) {
                dfs2(g[v][i], 1);
            } else {
                dfs2(g[v][i], 0);
            }
        }
    }
}

int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &cost[i]);
            police[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
            col[i] = 0;
        }
        col[n] = 0;
        dfs(1);
        printf("%lld\n", min(wyn[1][0], wyn[1][1]));

        if (wyn[1][0] > wyn[1][1])
            dfs2(1, 1);
        else
            dfs2(1, 0);
        for (int i = 1; i <= n; i++)
            printf("%d", police[i]);
        printf("\n");
        for (int i = 1; i <= n; i++)
            g[i].clear();
    }
    return 0;
}
