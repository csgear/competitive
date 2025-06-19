// https://dmoj.ca/problem/ccc01j1

#include <iostream>
using namespace std;

void printStar(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
}

void printSpace(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}
int main() {
    int H;
    cin >> H;

    int star;
    int space;
    for (int i = 0; i < H; i++) {
        if (i >= H / 2 + 1) {
            star = 1 + (H - i - 1) * 2;
        } else {
            star = 1 + i * 2;
        }
        space = 2 * H - 2 * star;
        printStar(star);
        printSpace(space);
        printStar(star);
        cout << endl;
    }

    return 0;
}
