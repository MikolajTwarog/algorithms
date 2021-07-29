#include <bits/stdc++.h>
using namespace std;

char room[405][405];

int match[161010];
bool visited[161010];

bool turbomatching(int v, int n) {
    // cout << v << "\n";
    if (visited[v])
        return false;

    visited[v] = true;

    int vi = v % (n + 1);
    int vj = v / (n + 1);
    // cout << v << " " << vi << " " << vj << "\n";

    for (int j = vj - 1; j <= vj + 1; j++) {
        if (j == vj)
            continue;
        for (int i = vi - 1; i <= vi + 1; i++) {
            int u = j * (n + 1) + i;
            visited[u] = true;
            // cout << u << "\n";
            if (room[i][j] == '.' &&
                (match[u] == 0 || turbomatching(match[u], n))) {

                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }

    // visited[v] = 0;
    return false;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> room[i][j];

        int res = 1;
        while (res > 0) {
            for (int i = 0; i <= (n + 1) * (m + 1); i++)
                visited[i] = false;
            res = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j += 2)
                    if (room[i][j] == '.' && match[i + j * (n + 1)] == 0) {
                        res += turbomatching(i + j * (n + 1), n);
                    }
            }
        }
        // for (int i = 1; i <= (n + 1) * (m + 1); i++)
        //     cout << visited[i] << " ";
        // cout << "\n";

        int wyn = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (room[i][j] == '.' && visited[i + j * (n + 1)] == j % 2)
                    wyn++;
            }
        }
        cout << wyn << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (room[i][j] == 'x') {
                    cout << 'x';
                    continue;
                }
                if (visited[i + j * (n + 1)] == j % 2)
                    cout << 's';
                else
                    cout << '.';
            }
            cout << "\n";
        }

        // for (int i = 1; i < (n + 1) * (m + 1); i++)
        //     cout << match[i] << " ";
        // cout << "\n";

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                match[i + j * (n + 1)] = 0;
                visited[i + j * (n + 1)] = false;
                room[i][j] = 0;
            }
        }
    }
}