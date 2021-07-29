#include <climits>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct state {
    int jars[3];
};

bool operator<(state a, state b) {
    if (a.jars[0] == b.jars[0]) {
        if (a.jars[1] == b.jars[1])
            return a.jars[2] < b.jars[2];
        return a.jars[1] < b.jars[1];
    }
    return a.jars[0] < b.jars[0];
}

map<state, int> dist;

void dijkstra(state start, const state &sizes) {
    priority_queue<pair<int, state>> q;
    q.push(make_pair(0, start));
    dist[start] = 0;

    while (!q.empty()) {
        pair<int, state> curr = q.top();
        q.pop();
        if (dist[curr.second] < curr.first)
            continue;

        state currstate = curr.second;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j < 3; j++) {
                int k = (i + j) % 3;
                if (currstate.jars[k] == sizes.jars[k])
                    continue;
                int juice =
                    min(currstate.jars[i], sizes.jars[k] - currstate.jars[k]);
                state newstate;
                newstate.jars[i] = currstate.jars[i] - juice;
                newstate.jars[k] = currstate.jars[k] + juice;
                newstate.jars[(i + 3 - j) % 3] =
                    currstate.jars[(i + 3 - j) % 3];

                if (!dist.count(newstate) ||
                    dist[newstate] > curr.first + juice) {
                    q.push(make_pair(curr.first + juice, newstate));
                    dist[newstate] = curr.first + juice;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int z;
    cin >> z;
    while (z--) {
        int n;
        state sizes;
        cin >> sizes.jars[0] >> sizes.jars[1] >> sizes.jars[2] >> n;

        state start;
        start.jars[0] = sizes.jars[0];
        start.jars[1] = 0;
        start.jars[2] = 0;
        dijkstra(start, sizes);

        int wyn = INT_MAX;

        for (pair<state, int> i : dist) {
            // cout << i.first.jars[0] << " " << i.first.jars[1] << " "
            //   << i.first.jars[2] << " " << i.second << "\n";
            if (i.first.jars[0] == n || i.first.jars[1] == n ||
                i.first.jars[2] == n)
                wyn = min(wyn, i.second);
        }

        if (wyn == INT_MAX)
            cout << "NIE\n";
        else
            cout << wyn << "\n";

        dist.clear();
    }
}