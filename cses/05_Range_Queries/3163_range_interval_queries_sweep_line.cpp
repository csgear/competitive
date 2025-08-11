// https://cses.fi/problemset/task/3163
// Sweep Line Algorithm + Offline Processing

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

// 树状数组
int bit[N];
int n, q;

int lowbit(int x) { return x & -x; }

void bit_update(int pos, int delta) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        bit[i] += delta;
    }
}

int bit_query(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}

int bit_range_query(int l, int r) {
    if (l > r) return 0;
    return bit_query(r) - bit_query(l - 1);
}

struct Event {
    int val, pos, type, query_id;
    // val: 值域坐标, pos: 位置坐标
    // type: 0 = 添加元素, 1 = 正查询, 2 = 负查询
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> all_values;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all_values.push_back(a[i]);
    }

    vector<array<int, 4>> queries(q);
    vector<int> answers(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
        all_values.push_back(queries[i][2]);
        all_values.push_back(queries[i][3]);
    }

    // 离散化
    sort(all_values.begin(), all_values.end());
    all_values.erase(unique(all_values.begin(), all_values.end()), all_values.end());

    auto compress = [&](int val) {
        return lower_bound(all_values.begin(), all_values.end(), val) - all_values.begin() + 1;
    };

    // 按值域扫描线处理
    vector<Event> events;

    // 添加所有数组元素作为事件
    for (int i = 1; i <= n; i++) {
        events.push_back({compress(a[i]), i, 0, -1});  // 修正：val是值域，pos是位置
    }

    // 添加查询事件
    for (int i = 0; i < q; i++) {
        int a_pos = queries[i][0], b_pos = queries[i][1];
        int c_val = compress(queries[i][2]), d_val = compress(queries[i][3]);

        // 对于每个查询，我们需要计算在位置区间[a,b]内值在[c,d]范围内的元素个数
        // 使用容斥原理：count(≤d) - count(≤c-1)
        events.push_back({d_val, b_pos, 1, i});          // +count(≤d, ≤b)
        events.push_back({d_val, a_pos - 1, 2, i});      // -count(≤d, ≤a-1)
        events.push_back({c_val - 1, b_pos, 2, i});      // -count(≤c-1, ≤b)
        events.push_back({c_val - 1, a_pos - 1, 1, i});  // +count(≤c-1, ≤a-1)
    }

    // 按值域排序
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.val != b.val) return a.val < b.val;
        return a.type < b.type;  // 先处理添加元素，再处理查询
    });

    // 处理事件
    for (const Event& event : events) {
        if (event.type == 0) {
            // 添加元素到树状数组（在位置event.pos加1）
            bit_update(event.pos, 1);
        } else if (event.type == 1) {
            // 查询并加到答案（查询位置≤event.pos的元素个数）
            answers[event.query_id] += bit_query(event.pos);
        } else {
            // 查询并从答案减去（查询位置≤event.pos的元素个数）
            answers[event.query_id] -= bit_query(event.pos);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << answers[i] << '\n';
    }

    return 0;
}