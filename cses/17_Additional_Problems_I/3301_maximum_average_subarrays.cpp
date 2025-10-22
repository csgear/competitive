// https://cses.fi/problemset/task/3301

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 叉积：判断 (O, A) 到 (O, B) 的转向
// >0: 逆时针（左转），<0: 顺时针（右转）
ll cross(const pair<ll, ll>& O, const pair<ll, ll>& A, const pair<ll, ll>& B) {
    return (A.first - O.first) * (B.second - O.second) -
           (A.second - O.second) * (B.first - O.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<ll> S(n + 1);
    S[0] = 0;
    for (int i = 0; i < n; i++) {
        S[i + 1] = S[i] + x[i];
    }

    deque<int> hull;
    hull.push_back(0);  // 初始点 (0, 0)

    vector<int> ans(n);

    for (int i = 1; i <= n; i++) {
        // ====== 查询：找最佳 j，使斜率最大 ======
        int best_j = hull[0];
        if (hull.size() > 1) {
            // 在凸壳上二分查找切点
            int left = 0, right = hull.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                int j1 = hull[mid];      // 点1
                int j2 = hull[mid + 1];  // 点2

                // 计算斜率：(S[i]-S[j]) / (i - j)
                // 比较 slope(j1) 和 slope(j2)
                // 为了避免浮点误差，交叉相乘比较
                ll dy1 = S[i] - S[j1], dx1 = i - j1;
                ll dy2 = S[i] - S[j2], dx2 = i - j2;

                // 如果 dy1/dx1 >= dy2/dx2
                if (dy1 * dx2 >= dy2 * dx1) {
                    right = mid;  // j1 更好或相等，往左走
                } else {
                    left = mid + 1;
                }
            }
            best_j = hull[left];
        }

        // 记录答案：子数组长度
        ans[i - 1] = i - best_j;

        // ====== 插入：将 (i, S[i]) 加入凸壳 ======
        while (hull.size() >= 2) {
            int last = hull.back();                   // 最后一个点
            int second_last = hull[hull.size() - 2];  // 倒数第二个点

            pair<ll, ll> A = {second_last, S[second_last]};
            pair<ll, ll> B = {last, S[last]};
            pair<ll, ll> C = {i, S[i]};

            // 如果 A->B->C 是顺时针，删除 B
            if (cross(A, B, C) <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(i);
    }

    // 输出答案
    for (int len : ans) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}