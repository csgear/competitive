// https://dmoj.ca/problem/ccc00s1

#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, m1, m2, m3;
    cin >> q >> m1 >> m2 >> m3;

    int plays = 0;

    while (q > 0) {
        int m = plays % 3;
        plays++;
        q--;

        switch (m) {
            case 0:
                m1 = (m1 + 1) % 35;
                if (m1 == 0) q += 30;
                break;

            case 1:
                m2 = (m2 + 1) % 100;
                if (m2 == 0) q += 60;
                break;

            case 2:
                m3 = (m3 + 1) % 10;
                if (m3 == 0) q += 9;
                break;
        }
    }

    cout << "Martha plays " << plays << " times before going broke." << endl;
    return 0;
}