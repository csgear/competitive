// https://usaco.org/index.php?page=viewproblem2&cpid=1059
// USACO 2020 December Contest, Bronze
// Problem 1. Do You Know Your ABCs?

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(7);
    for (int i = 0; i < 7; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int a = nums[0];
    int b = nums[1];
    int c = nums[6] - a - b;

    cout << a << " " << b << " " << c << endl;
}