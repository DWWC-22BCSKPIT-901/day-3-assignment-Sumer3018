#include <iostream>
using namespace std;

bool isMatchRecursive(string s, string p, int i = 0, int j = 0) {
    if (j == p.size()) return i == s.size();
    if (p[j] == '*') {
        return isMatchRecursive(s, p, i, j + 1) || (i < s.size() && isMatchRecursive(s, p, i + 1, j));
    }
    return i < s.size() && (p[j] == '?' || p[j] == s[i]) && isMatchRecursive(s, p, i + 1, j + 1);
}

int main() {
    string s = "aa", p = "*";
    cout << (isMatchRecursive(s, p) ? "true" : "false") << endl;

    s = "cb", p = "?a";
    cout << (isMatchRecursive(s, p) ? "true" : "false") << endl;

    return 0;
}
