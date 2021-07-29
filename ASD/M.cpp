#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[1000010];
bool marked[1000010];
int routes[1000010];
bool used[1000010];
bool visited[1000010];

void dfs(int v) {
    visited[v] = true;

    int wyn = 0;
    int unused = marked[v];
    bool vused = false;
    for (int i = 0; i < tree[v].size(); i++) {
        if (!visited[tree[v][i]]) {
            dfs(tree[v][i]);
            wyn += routes[tree[v][i]];
            unused += !used[tree[v][i]];
            if (!vused && unused >= 2) {
                vused = true;
                unused -= 2;
                wyn++;
            }
        }
    }
    routes[v] = wyn;
    used[v] = vused || unused == 0;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++) {
            tree[i].clear();
            routes[i] = -1;
            marked[i] = false;
            visited[i] = false;
        }

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            marked[a] = true;
        }

        dfs(1);

        cout << routes[1] << endl;
    }
}