#include <bits/stdc++.h>
using namespace std;

long long cap[210][210];
// int f[210][210];

long long make_flow(int s, int t, int *prev) {
    int v = t;
    long long mn = INT32_MAX;
    // for (int i = 0; i < 10; i++)
    //     cout << prev[i] << " ";
    // cout << "\n";
    while (v != s) {
        // cout << t;
        mn = min(mn, cap[prev[v]][v]);
        v = prev[v];
    }
    // cout << "mn " << mn << "\n";
    v = t;
    while (v != s) {
        cap[prev[v]][v] -= mn;
        cap[v][prev[v]] += mn;
        v = prev[v];
    }

    return mn;
}

long long bfs(int s, int t, int n) {
    queue<int> q;
    q.push(s);
    int prev[210];
    for (int i = 0; i < n; i++)
        prev[i] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == t) {
            return make_flow(s, t, prev);
        }
        for (int i = 0; i < n; i++) {
            if (cap[v][i] > 0 && prev[i] == -1) {
                q.push(i);
                prev[i] = v;
            }
        }
    }

    return -1;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        for (int i = 2; i < n + 2; i++) {
            int a;
            cin >> a;
            cap[0][i] = a;
        }

        for (int i = n + 2; i < n + m + 2; i++) {
            int a;
            cin >> a;
            cap[i][1] = a;
        }

        for (int i = 2; i < n + 2; i++) {
            for (int j = n + 2; j < n + m + 2; j++) {
                int a;
                cin >> a;
                if (a == 1)
                    cap[i][j] = INT32_MAX;
                else
                    cap[i][j] = 0;
            }
        }

        long long wyn = 0;
        while (true) {
            int temp = bfs(0, 1, n + m + 2);
            // cout << "temp " << temp << "\n";
            if (temp <= 0)
                break;
            wyn += temp;
        }
        cout << wyn << "\n";

        for (int i = 0; i < n + m + 2; i++) {
            for (int j = 0; j < n + m + 2; j++) {
                cap[i][j] = 0;
            }
        }
    }
}