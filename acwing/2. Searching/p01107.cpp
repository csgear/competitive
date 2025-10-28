// https://www.acwing.com/problem/content/1109/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
unordered_map<string, pair<string, char>> pre;

// swap second line with first line
string moveA(string s) {
    for (int i = 0; i < 4; i++) {
        swap(s[i], s[i + 4]);
    }
    return s;
}

// move last column to first column
string moveB(string s) {
    char temp0 = s[3], temp1 = s[7];
    for (int i = 3; i > 0; i--) {
        s[i] = s[i - 1];
        s[i + 4] = s[i + 3];
    }
    s[0] = temp0;
    s[4] = temp1;
    return s;
}

// rotate middle four elements clockwise
string moveC(string s) {
    swap(s[1], s[5]);
    swap(s[2], s[5]);
    swap(s[5], s[6]);
    return s;
}

void bfs(string start, string end) {
    queue<string> q;
    q.push(start);
    mp[start] = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        string moves[] = {moveA(s), moveB(s), moveC(s)};
        char moveNames[] = {'A', 'B', 'C'};
        for (int i = 0; i < 3; i++) {
            string next = moves[i];
            if (!mp.count(next)) {
                mp[next] = mp[s] + 1;
                pre[next] = {s, moveNames[i]};
                if (next == end) break;
                q.push(next);
            }
        }
    }
}

int main() {
    string start = "12348765", end = "";
    for (int i = 1; i <= 8; i++) {
        int n;
        cin >> n;
        end += to_string(n);
    }

    reverse(end.begin() + 4, end.end());

    bfs(start, end);

    if (mp.count(end)) {
        cout << mp[end] << endl;
        if (mp[end] == 0) return 0;
        string path = "";
        string cur = end;
        while (cur != start) {
            path += pre[cur].second;
            cur = pre[cur].first;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    return 0;
}