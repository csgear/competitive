#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vec = struct {
    ll x, y;
} ;

char tachyon[256][256] = {'\0'};

int split_count(vec start_pos) {
    vec cur = start_pos;
    char c ;
    while('.' == (c = tachyon[cur.y + 1][cur.x])) {
        tachyon[cur.y+1][cur.x] = '|';
        cur.y++;
    }

     if (c == '^') {
        return 1 + split_count({cur.x - 1, cur.y}) + split_count({cur.x + 1, cur.y});
     }

     return 0 ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 256 && NULL != fgets(tachyon[i], 256, stdin); i++) {
        // Process each line of input if needed
    }

    char *start = strchr(tachyon[0], 'S');

    vec start_pos = {0, 0};

    start_pos.x = start - tachyon[0];

    cout << split_count(start_pos) << "\n";

    return 0;

}
