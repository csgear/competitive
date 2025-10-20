// https://cses.fi/problemset/task/2085
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct Line {
    ll m, b;
    ll eval(ll x) { return m * x + b; }
};

struct LiChaoTree {
    struct Node {
        Line line;
        Node* left;
        Node* right;
        Node() : line({0, INF}), left(nullptr), right(nullptr) {}
    };

    Node* root;
    ll minX, maxX;

    LiChaoTree(ll _minX, ll _maxX) : minX(_minX), maxX(_maxX) { root = new Node(); }

    void update(Node* node, ll tl, ll tr, Line newLine) {
        if (tl == tr) {
            if (newLine.eval(tl) < node->line.eval(tl)) {
                node->line = newLine;
            }
            return;
        }

        ll tm = (tl + tr) / 2;
        bool left_better = newLine.eval(tl) < node->line.eval(tl);
        bool mid_better = newLine.eval(tm) < node->line.eval(tm);

        if (mid_better) {
            swap(node->line, newLine);
        }

        if (left_better != mid_better) {
            if (!node->left) node->left = new Node();
            update(node->left, tl, tm, newLine);
        } else {
            if (!node->right) node->right = new Node();
            update(node->right, tm + 1, tr, newLine);
        }
    }

    ll query(Node* node, ll tl, ll tr, ll x) {
        if (!node) return INF;
        if (tl == tr) {
            return node->line.eval(x);
        }

        ll tm = (tl + tr) / 2;
        ll result = node->line.eval(x);

        if (x <= tm) {
            if (node->left) {
                result = min(result, query(node->left, tl, tm, x));
            }
        } else {
            if (node->right) {
                result = min(result, query(node->right, tm + 1, tr, x));
            }
        }

        return result;
    }

    void addLine(Line line) { update(root, minX, maxX, line); }

    ll getMin(ll x) { return query(root, minX, maxX, x); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> s(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> f[i];

    // Find coordinate range for Li Chao Tree
    ll minS = *min_element(s.begin() + 1, s.end());
    ll maxS = *max_element(s.begin() + 1, s.end());

    vector<ll> dp(n + 1, INF);
    LiChaoTree lct(minS, maxS);

    // Base case: start with initial skill factor x
    dp[0] = 0;
    lct.addLine({x, 0});

    for (int i = 1; i <= n; i++) {
        dp[i] = lct.getMin(s[i]);
        lct.addLine({f[i], dp[i]});
    }

    cout << dp[n] << '\n';

    return 0;
}