// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
using namespace std;

// Gray code formula approach: G(n) = n XOR (n >> 1)
// This formula directly converts binary number to Gray code
// Gray code property: adjacent codes differ by exactly one bit
vector<string> gray1(int n) {
    int total = 1 << n;  // 2^n total Gray codes
    vector<string> result;

    for (int i = 0; i < total; ++i) {
        // This gives the i-th Gray code from binary i
        int gray = i ^ (i >> 1);

        // Convert Gray code number to binary string
        string s;
        for (int j = n - 1; j >= 0; --j) {
            s += ((gray >> j) & 1) ? '1' : '0';
        }
        result.push_back(s);
    }
    return result;
}

vector<string> gray2(int n) {
    if (n == 1) return {"0", "1"};
    vector<string> prev = gray2(n - 1);
    vector<string> result;
    // Prefix 0
    for (const string& s : prev) result.push_back("0" + s);
    // Prefix 1 (reverse order)
    for (int i = prev.size() - 1; i >= 0; --i) result.push_back("1" + prev[i]);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> gray_codes;

    gray_codes = gray1(n);
    for (const string& code : gray_codes) cout << code << '\n';
    return 0;
}
