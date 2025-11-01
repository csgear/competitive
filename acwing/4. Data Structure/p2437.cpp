// https://www.acwing.com/problem/content/2439/
// 2437. Splay

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;  // 节点数上限（含哨兵）

int n, m, root, idx;  // root: 树根, idx: 节点分配器
int w[N];             // 用于建树的初始数组

// Splay 节点定义
struct Node {
    int s[2];  // s[0]: 左儿子, s[1]: 右儿子
    int p;     // 父节点
    int v;     // 存储的值（本题为 1~n）
    int rev;   // 翻转懒标记（1 表示需要翻转）
    int size;  // 子树大小（用于找第 k 个）
    void init(int _v, int _p) {
        s[0] = s[1] = 0;
        p = _p;
        v = _v;
        size = 1;
    }
} tr[N];

void push_up(int x) {
    if (!x) return;
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

void push_down(int x) {
    if (!x || !tr[x].rev) return;
    tr[x].rev = 0;
    swap(tr[x].s[0], tr[x].s[1]);  // 翻转 = 交换左右子树
    if (tr[x].s[0]) tr[tr[x].s[0]].rev ^= 1;
    if (tr[x].s[1]) tr[tr[x].s[1]].rev ^= 1;
}

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = (tr[y].s[1] == x);
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    push_up(y), push_up(x);
}

void splay(int x, int goal) {
    while (tr[x].p != goal) {
        int y = tr[x].p, z = tr[y].p;
        if (z != goal) {
            if ((tr[z].s[1] == y) ^ (tr[y].s[1] == x))
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
    if (goal == 0) root = x;
}

int build(int l, int r, int p) {
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    int u = ++idx;
    tr[u].init(w[mid], p);
    tr[u].s[0] = build(l, mid - 1, u);  // 左子树
    tr[u].s[1] = build(mid + 1, r, u);  // 右子树
    push_up(u);
    return u;
}

// 找中序遍历第 k 个节点（1-based）
int get_kth(int k) {
    int u = root;
    while (u) {
        push_down(u);  // 访问前必须下传标记！
        if (tr[tr[u].s[0]].size >= k)
            u = tr[u].s[0];  // 在左子树
        else if (tr[tr[u].s[0]].size + 1 == k)
            return u;  // 当前就是第 k 个
        else {
            k -= tr[tr[u].s[0]].size + 1;  // 跳过左子树+根
            u = tr[u].s[1];              // 进右子树
        }
    }
    return -1;
}

// 反转原数组的区间 [l, r]（1-based）
void reverse_range(int l, int r) {
    // 哨兵保护：实际操作树中 [l, r+2]
    int x = get_kth(l);      // 前驱：中序第 l 个（原 l-1 位置）
    int y = get_kth(r + 2);  // 后继：中序第 r+2 个（原 r+1 位置）
    splay(x, 0);             // y 转到根
    splay(y, x);             // x 转到 y 的左儿子
    // 此时 y 的左子树就是 [l, r] 对应的整棵子树
    int mid = tr[y].s[0];
    if (mid) tr[mid].rev ^= 1;  // 打翻转标记
}

void output(int u) {
    push_down(u);
    if (tr[u].s[0]) output(tr[u].s[0]);                        // 先遍历左子树
    if (tr[u].v >= 1 && tr[u].v <= n) printf("%d ", tr[u].v);  // 输出这个点
    if (tr[u].s[1]) output(tr[u].s[1]);                        // 后遍历右子树
}

// 主函数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tr[0].size = 0;  // 空节点大小为 0（必须！）

    cin >> n >> m;

    // 初始序列是 1, 2, ..., n（题目特性）
    for (int i = 1; i <= n; i++) w[i] = i;
    w[0] = w[n + 1] = -1;  // 哨兵（值任意，不影响输出）

    root = build(0, n + 1, 0);  // 构建带哨兵的平衡树

    while (m--) {
        int l, r;
        cin >> l >> r;
        reverse_range(l, r);  // 反转 [l, r]
    }

    output(root);  // 输出结果
    printf("\n");

    return 0;
}