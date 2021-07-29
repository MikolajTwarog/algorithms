#include <bits/stdc++.h>
using namespace std;

struct state {
    int child[2], fail;
    bool terminal;
    state() {
        child[0] = child[1] = -1;
        fail = 0;
        terminal = false;
    }
    int &operator[](char c) { return child[c - '0']; }
    int &operator[](int i) { return child[i]; }
};

void add_to_tree(vector<state> &tree, string word) {
    int current = 0;
    for (int i = 0; i < word.length(); i++) {
        if (tree[current][word[i]] == -1) {
            state new_state;
            tree.push_back(new_state);
            tree[current][word[i]] = tree.size() - 1;
            current = tree.size() - 1;
        } else {
            current = tree[current][word[i]];
        }
    }
    tree[current].terminal = true;
}

bool dfs(vector<state> &tree, vector<int> &visited, int v) {
    visited[v] = 1;
    bool result = 0;
    for (int i = 0; i < 2; i++) {
        // cout << tree[v][i] << endl;
        if (visited[tree[v][i]] == 1)
            return true;
        if (visited[tree[v][i]] == 0 && !tree[tree[v][i]].terminal)
            result = max(result, dfs(tree, visited, tree[v][i]));
    }
    visited[v] = 2;
    return result;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<state> tree;
        state root;
        tree.push_back(root);

        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            add_to_tree(tree, word);
        }

        queue<int> q;
        for (int i = 0; i < 2; i++) {
            int &next = tree[0][i];
            if (next == -1) {
                next = 0;
            } else {
                q.push(next);
            }
        }

        while (!q.empty()) {
            int s = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int next = tree[s][i];
                if (next != -1) {
                    q.push(next);
                    int x = tree[s].fail;
                    while (tree[x][i] == -1)
                        x = tree[x].fail;
                    tree[next].fail = tree[x][i];
                }
            }
        }


        for (int i = 0; i < 2; i++) {
            if (tree[0][i] != 0) {
                q.push(tree[0][i]);
            }
        }

        while (!q.empty()) {
            int s = q.front();
            q.pop();
            if (tree[tree[s].fail].terminal)
                tree[s].terminal = true;
            for (int i = 0; i < 2; i++) {
                int next = tree[s][i];
                if (next == -1) {
                    int x = tree[s].fail;
                    while (tree[x][i] == -1)
                        x = tree[x].fail;
                    tree[s][i] = tree[x][i];
                } else {
                    q.push(next);
                }
            }
        }

        // for (int i = 0; i < tree.size(); i++) {
        //     cout << i << " " << tree[i][0] << " " << tree[i][1] << " " << tree[i].terminal << endl;
        // }

        vector<int> visited(tree.size());
        if (dfs(tree, visited, 0))
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}