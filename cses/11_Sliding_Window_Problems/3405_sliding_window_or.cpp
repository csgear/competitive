// https://cses.fi/problemset/task/3405

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    stack<pair<ll, ll>> in, out;  // {value, running_OR}

    auto push_in = [&](ll val) {
        ll cur_or = in.empty() ? val : (in.top().second | val);
        in.push({val, cur_or});
    };

    auto move_to_out = [&]() {
        while (!in.empty()) {
            ll val = in.top().first;
            in.pop();
            ll cur_or = out.empty() ? val : (out.top().second | val);
            out.push({val, cur_or});
        }
    };

    auto pop_queue = [&]() {
        if (out.empty()) {
            move_to_out();
        }
        out.pop();
    };

    auto query_or = [&]() {
        ll result = 0;
        if (!in.empty()) result |= in.top().second;
        if (!out.empty()) result |= out.top().second;
        return result;
    };

    // Build initial window
    for (int i = 0; i < k; i++) {
        push_in(x);
        x = (x * a + b) % c;
    }

    ll ans = query_or();

    // Slide the window
    for (int i = k; i < n; i++) {
        pop_queue();
        push_in(x);
        ans ^= query_or();
        x = (x * a + b) % c;
    }

    cout << ans << endl;
    return 0;
}