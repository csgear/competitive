// https://cses.fi/problemset/task/1692

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> visited;
    string sequence;

    auto dfs = [&](const string& node, auto& self) -> void {
        for (char c : {'0', '1'}) {
            string edge = node + c;
            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                self(edge.substr(1), self);
                sequence += c;
            }
        }
    };

    string start(n - 1, '0');
    dfs(start, dfs);

    // Reverse the sequence since we built it during backtracking
    reverse(sequence.begin(), sequence.end());
    string result = start + sequence;

    cout << result << endl;
    return 0;
}