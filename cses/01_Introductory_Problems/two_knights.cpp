// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

#define ll long long

int main() {
  fastio;

  int n;
  cin >> n;

  for (long long k = 1; k <= n; k++) {
    ll total = (k * k * (k * k - 1)) / 2LL;
    ll attack = 4LL * (k - 1) * (k - 2);
    cout << total - attack << endl;
  }
  return 0;
}
