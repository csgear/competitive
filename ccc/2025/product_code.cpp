#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        string letters;
        int sum = 0;
        int number = 0;
        int sign = 1;
        bool inNumber = false;

        for (char c : s) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
                inNumber = true;
            } else {
                if (inNumber) {
                    sum += sign * number;
                    number = 0;
                    sign = 1;
                    inNumber = false;
                }

                if (c == '-') {
                    sign = -1;
                    inNumber = true;
                } else if (isupper(c)) {
                    letters += c;
                }
            }
        }

        if (inNumber) {
            sum += sign * number;
        }

        cout << letters << sum << '\n';
    }

    return 0;
}
