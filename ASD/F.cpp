#include <iostream>
#include <vector>
using namespace std;

vector<int> g1[500010];
vector<int> g2[500010];
int l[500010];
int r[500010];

void dfs1(int v) {
    int wyn = 0;
    for (int i : g1[v]) {
        if (l[i] == -1)
            dfs1(i);
        wyn = max(wyn, l[i]);
    }
    l[v] = wyn + 1;
}

void dfs2(int v) {
    int wyn = 0;
    for (int i : g2[v]) {
        if (r[i] == -1)
            dfs2(i);
        wyn = max(wyn, r[i]);
    }
    r[v] = wyn + 1;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            g1[i].clear();
            g2[i].clear();
            l[i] = -1;
            r[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g1[a].push_back(b);
            g2[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (l[i] == -1)
                dfs1(i);
            if (r[i] == -1)
                dfs2(i);

            cout << l[i] + r[i] - 1 << " ";
        }
        cout << endl;
    }
}