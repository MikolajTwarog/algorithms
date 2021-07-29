#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int cuts[410];
long long tab[410][410];
long long seq[410][410];

long long oneCutCost(int beg, int len, int c) {
    return max(cuts[beg + c] - cuts[beg], cuts[beg + len] - cuts[beg + c]);
}

long long minCost(int beg, int len) {
    long long wyn = LONG_LONG_MAX;
    // cout << beg << " " << len << endl;
    for (int i = 1; i < len; i++) {
        if (wyn >
            oneCutCost(beg, len, i) + tab[beg][i] + tab[beg + i][len - i]) {
            wyn = oneCutCost(beg, len, i) + tab[beg][i] + tab[beg + i][len - i];
            seq[beg][len] = i;
        }
        /* cout << "cost "
              << oneCutCost(beg, len, i) + tab[beg][i] + tab[beg + i][len - i]
              << endl;*/
    }
    return wyn;
}

void order(int beg, int len) {
    if (len <= 1)
        return;
    cout << cuts[seq[beg][len] + beg] << " ";
    order(beg, seq[beg][len]);
    order(beg + seq[beg][len], len - seq[beg][len]);
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, d;
        cin >> d >> n;

        for (int i = 0; i < n; i++) {
            cin >> cuts[i];
        }

        cuts[n] = 0;
        cuts[n + 1] = d;
        n += 2;
        sort(cuts, cuts + n);

        for (int i = 0; i < n; i++) {
            tab[i][0] = 0;
            tab[i][1] = 0;
        }

        for (int j = 2; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                tab[i][j] = minCost(i, j);
                // cout << i << " " << j << "\n";
            }
        }

        /*for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                cout << seq[i][j] << " ";
            }
            cout << "\n";
        }*/

        cout << tab[0][n - 1] << endl;
        order(0, n - 1);
        cout << endl;
    }
}