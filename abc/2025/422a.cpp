// https://atcoder.jp/contests/abc422/tasks/abc422_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j;
    scanf("%d-%d", &i, &j);
    if (j < 8) j++;
    if (j == 8 && i < 8) {
        i++;
        j = 1;
    }
    cout << i << "-" << j << endl;
    return 0;
}