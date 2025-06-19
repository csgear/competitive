// https://dmoj.ca/problem/ccc00j2

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int cnt = 0;

    // convert a number to string
    // check if it only contains 0, 1, 8, 6, 9
    // replace 6 with 9 and 9 with 6
    // compare the reverse of the string == orignal
    // if all yes, add cnt + 1

    for (int i = m; i <= n; i++) {
        string num = to_string(i);

        bool valid = true;

        for (char c : num) {
            if (c != '0' && c != '1' && c != '8' && c != '6' && c != '9') {
                valid = false;
                break;
            }
        }

        if (valid) {
            // Create the rotated version of the number
            string rotated = "";
            for (int j = num.length() - 1; j >= 0; j--) {
                if (num[j] == '6')
                    rotated += '9';
                else if (num[j] == '9')
                    rotated += '6';
                else
                    rotated += num[j];
            }

            if (rotated == num) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}