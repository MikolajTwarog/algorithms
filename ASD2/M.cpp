#include <bits/stdc++.h>
using namespace std;


void prefix_prefix(string & text, int *result) {
    int start = 0;
    int end = 0;
    int len = text.size();
    for (int i = 1; i < len; i++) {
        result[i] = 0;
        if (i < end)
            result[i] = min(result[i - start], end - i);
        while (result[i] + i < len && text[i + result[i]] == text[result[i]])
            result[i]++;
        if (result[i] + i > end) {
            end = result[i] + i;
            start = i;
        }
    }
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        string pattern, text;
        cin >> pattern >> text;
        text = pattern + '^' + text  + '$' + pattern;
        int pre_result[text.size()];
        prefix_prefix(text, pre_result);

        reverse(text.begin(), text.end());
        int suf_result[text.size()];
        prefix_prefix(text, suf_result);
        reverse(suf_result, suf_result+text.size());

        bool res = false;
        for (int i = pattern.size() + 1; i < text.size() - 2*pattern.size(); i++) {
            if (pre_result[i] + suf_result[i + pattern.size() - 1] + 1 >= pattern.size()) {
                res = true;
                break;
            }
        }
        res ? cout << "TAK" : cout << "NIE";
        cout << endl;
    }
}





python3 test.py > O.in
./O < O.in > my.out
./Okr < O.in > exp.out
cmp exp.out my.out
