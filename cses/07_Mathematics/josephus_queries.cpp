// https://cses.fi/problemset/task/2164

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll josephus(ll n, ll k) {
  if (n == 1) {
    return 1;
  } else {
    return (josephus(n - 1, k) + (k - 1)) % n + 1;
  }
}

int josephus_1(int N, int k) {
  int i = 1, ans = 0;
  while (i <= N) {
    ans = (ans + k) % i;
    i++;
  }
  return ans + 1;
}

int main() {
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    ll n, k;
    cin >> n >> k;
    cout << josephus_1(n, k) << endl;
  }
  return 0;
}