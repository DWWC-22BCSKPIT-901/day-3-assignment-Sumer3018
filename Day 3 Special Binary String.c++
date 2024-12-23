#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Include this for accumulate
using namespace std;

string makeLargestSpecialRecursive(string s) {
    vector<string> subs;
    int count = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        count += s[i] == '1' ? 1 : -1;
        if (count == 0) {
            subs.push_back("1" + makeLargestSpecialRecursive(s.substr(start + 1, i - start - 1)) + "0");
            start = i + 1;
        }
    }

    sort(subs.rbegin(), subs.rend());
    return accumulate(subs.begin(), subs.end(), string());
}

int main() {
    string s = "11011000";
    cout << makeLargestSpecialRecursive(s) << endl;

    s = "10";
    cout << makeLargestSpecialRecursive(s) << endl;

    return 0;
}
