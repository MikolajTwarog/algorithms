#pragma GCC optimize("Ofast")

#include <iostream>
using namespace std;

struct permutation {
    int tab[9];
};

permutation operator*(permutation &a, permutation &b) {
    permutation wyn;
    for (int i = 1; i <= 8; i++) {
        wyn.tab[i] = a.tab[b.tab[i]];
    }
    return wyn;
}

void pprint(permutation &a) {
    for (int i = 1; i <= 8; i++) {
        cout << a.tab[i] << " ";
    }
    cout << endl;
}

void pscan(permutation &a) {
    for (int i = 1; i <= 8; i++)
        cin >> a.tab[i];
}

permutation tree[800010];
int lopow;

void init_tree(int n) {
    lopow = 1;
    while (n > lopow)
        lopow *= 2;
    for (int i = 0; i < n; i++) {
        pscan(tree[lopow + i]);
        // pprint(tree[lopow + i]);
    }
    for (int i = n; i < lopow; i++) {
        for (int j = 1; j <= 8; j++)
            tree[lopow + i].tab[j] = j;
        // pprint(tree[lopow + i]);
    }
    for (int i = lopow - 1; i > 0; i--) {
        tree[i] = tree[2 * i] * tree[2 * i + 1];
    }
}

void update(int k, permutation a) {
    k += lopow;
    tree[k] = a;
    for (int i = k / 2; i > 0; i /= 2) {
        tree[i] = tree[2 * i] * tree[2 * i + 1];
        // pprint(tree[i]);
    }
}

int main() {
    int n;
    cin >> n;
    init_tree(n);

    // permutation temp = tree[1] * tree[2];
    // pprint(temp);
    // for (int i = 0)

    int k;
    cin >> k;

    int j;
    permutation a;

    while (k--) {
        cin >> j;
        pscan(a);
        update(j - 1, a);
        pprint(tree[1]);
    }
}