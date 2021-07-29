#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct edge {
    int a, b, w, i;
};

bool operator<(edge a, edge b) { return a.w > b.w; }

priority_queue<edge> q;
int component[100010];
bool result[200010];

int find(int v) {
    if (v == component[v])
        return v;
    component[v] = find(component[v]);
    return component[v];
}

void unionn(int v, int w) { component[find(v)] = find(w); }

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            edge e;
            cin >> e.a >> e.b >> e.w;
            e.i = i;
            q.push(e);
        }

        for (int i = 0; i <= n; i++)
            component[i] = i;

        vector<edge> same;

        while (!q.empty()) {
            edge e = q.top();
            q.pop();
            if (!same.empty() && e.w != same.back().w) {
                for (edge i : same)
                    result[i.i] = find(i.a) != find(i.b);
                for (edge i : same)
                    unionn(i.a, i.b);

                same.clear();
            }
            same.push_back(e);
        }

        for (edge i : same)
            result[i.i] = find(i.a) != find(i.b);
        for (edge i : same)
            unionn(i.a, i.b);

        for (int i = 0; i < m; i++) {
            if (result[i])
                cout << "TAK\n";
            else
                cout << "NIE\n";
        }
    }
}