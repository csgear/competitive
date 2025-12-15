#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    if (lines.empty()) return 0;

    string lastLine = lines.back();
    lines.pop_back();

    // Find operator positions
    vector<int> indices;
    vector<char> ops;
    for (int i = 0; i < lastLine.size(); i++) {
        if (lastLine[i] == '+' || lastLine[i] == '*') {
            indices.push_back(i);
            ops.push_back(lastLine[i]);
        }
    }
    indices.push_back(lines.empty() ? lastLine.size() : lines[0].size());

    ll part1 = 0, part2 = 0;

    // Process each operation
    for (int i = 0; i < ops.size(); i++) {
        int start = indices[i];
        int end = indices[i + 1];
        int length = (i + 1 == ops.size()) ? (end - start) : (end - 1 - start);

        // Part 1: Process column-wise (row by row)
        ll result1 = 0;
        bool first1 = true;
        for (const string& l : lines) {
            if (start + length <= l.size()) {
                ll val = stoll(l.substr(start, length));
                if (first1) {
                    result1 = val;
                    first1 = false;
                } else {
                    result1 = (ops[i] == '+') ? result1 + val : result1 * val;
                }
            }
        }
        part1 += result1;

        // Part 2: Process row-wise (transpose then reduce)
        // Collect column strings first
        vector<string> colStrs;
        for (const string& l : lines) {
            if (start + length <= l.size()) {
                colStrs.push_back(l.substr(start, length));
            }
        }

        // Transpose and reduce
        if (!colStrs.empty()) {
            int numCols = colStrs[0].size();
            ll result2 = 0;
            bool first2 = true;

            for (int col = 0; col < numCols; col++) {
                string s;
                for (const string& str : colStrs) {
                    if (col < str.size()) {
                        s += str[col];
                    }
                }
                ll val = stoll(s);
                if (first2) {
                    result2 = val;
                    first2 = false;
                } else {
                    result2 = (ops[i] == '+') ? result2 + val : result2 * val;
                }
            }
            part2 += result2;
        }
    }

    cout << part1 << '\n';
    cout << part2 << '\n';

    return 0;
}