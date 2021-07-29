#include <iostream>
using namespace std;

struct node {
    int mx;
    int amount;
};

node tree[240010];
int lopow;

void init_tree(int n) {
    lopow = 1;
    while (lopow < n)
        lopow *= 2;
    for (int i = 1; i < lopow * 2; i++) {
        tree[i].mx = 0;
        tree[i].amount = 0;
    }
}

void add(int begin, int end, int amount) {
    begin += lopow;
    end += lopow;

    if (begin != end) {
        tree[begin].amount += amount;
        tree[begin].mx += amount;
    }
    tree[end].amount += amount;
    tree[end].mx += amount;

    while (end / 2 != begin / 2) {
        if (end % 2 == 1) {
            tree[end - 1].amount += amount;
            tree[end - 1].mx += amount;
        }
        if (begin % 2 == 0) {
            tree[begin + 1].amount += amount;
            tree[begin + 1].mx += amount;
        }

        begin /= 2;
        end /= 2;

        tree[begin].mx = max(tree[2 * begin].mx, tree[2 * begin + 1].mx) +
                         tree[begin].amount;
        tree[end].mx =
            max(tree[2 * end].mx, tree[2 * end + 1].mx) + tree[end].amount;
    }

    end /= 2;

    while (end > 0) {
        tree[end].mx =
            max(tree[2 * end].mx, tree[2 * end + 1].mx) + tree[end].amount;
        end /= 2;
    }
}

int get_max(int begin, int end) {
    begin += lopow;
    end += lopow;
    int wyn1 = tree[begin].amount, wyn2 = tree[end].amount;

    while (end / 2 != begin / 2) {
        if (end % 2 == 1)
            wyn2 = max(wyn2, tree[end - 1].mx);
        if (begin % 2 == 0)
            wyn1 = max(wyn1, tree[begin + 1].mx);

        end /= 2;
        begin /= 2;

        wyn1 += tree[begin].amount;
        wyn2 += tree[end].amount;
    }

    wyn1 = max(wyn1, wyn2);

    end /= 2;

    while (end > 0) {
        wyn1 += tree[end].amount;
        end /= 2;
    }

    return wyn1;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n, m, q;
        cin >> n >> m >> q;
        n--;
        init_tree(n);

        for (int i = 0; i < q; i++) {
            int begin, end, amount;
            cin >> begin >> end >> amount;
            begin--;
            end--;
            // cout << "MAX: " << get_max(begin, end - 1) << endl;
            if (get_max(begin, end - 1) + amount > m)
                cout << "N\n";
            else {
                cout << "T\n";
                add(begin, end - 1, amount);

                // for (int j = 1; j < lopow * 2; j++)
                //     cout << j << " +" << tree[j].amount << " " << tree[j].mx
                //          << endl;
            }
        }
    }
}