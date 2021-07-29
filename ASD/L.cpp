#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct shop {
    int start;
    int end;
    int cost;
};

bool shop_comp_start(shop a, shop b) { return a.start < b.start; }
bool shop_comp_end(shop a, shop b) { return a.end > b.end; }
bool shop_comp_cost(shop a, shop b) { return a.cost > b.cost; }
bool operator<(shop a, shop b) { return a.end > b.end; }

shop shops[5010];
shop wyn[5010];
shop wyn2[5010];

bool check(int end, shop curr) {
    for (int i = 0; i < end - 1; i++)
        wyn[i] = wyn2[i];
    wyn[end - 1] = curr;
    sort(wyn, wyn + end, shop_comp_start);

    int maxend = 0;
    for (int i = 0; i < end; i++)
        maxend = max(maxend, wyn[i].end);

    priority_queue<shop> q;

    /* cout << end << endl;
     for (int i = 0; i < end; i++)
         cout << wyn[i].start << endl;*/
    for (int i = 0, time = wyn[0].start; time <= maxend;) {
        // cout << "time " << time << endl;
        for (; i < end && wyn[i].start == time; i++) {
            // cout << "cost " << wyn[i].cost << endl;
            q.push(wyn[i]);
        }
        if (q.top().end <= time)
            return false;
        q.pop();
        if (i >= end && q.empty())
            break;
        if (q.empty())
            time = wyn[i].start;
        else
            time++;
    }
    return true;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> shops[i].start >> shops[i].end >> shops[i].cost;
        sort(shops, shops + n, shop_comp_cost);

        int maxcost = 0;
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (check(k + 1, shops[i])) {
                wyn2[k++] = shops[i];
                maxcost += shops[i].cost;
            }
        }

        cout << maxcost << endl;
    }
}