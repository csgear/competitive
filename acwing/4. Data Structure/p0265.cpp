// https://www.acwing.com/problem/content/267
// 265. 营业额统计
// 本题使用 FHQ Treap（无旋 Treap）维护一个动态有序集合，支持插入、前驱、后继等操作
// 用于解决“营业额统计”问题：每次插入一个数，求它与已插入数中最近值的差的绝对值，累加总和

#include <bits/stdc++.h>
using namespace std;

const int N = 40010;  // 最大节点数（题目中 n <= 40000）
const int INF = 1e7;  // 一个足够大的数，用于表示无穷大（前驱/后继不存在时返回）

// FHQ Treap 结构体
struct FHQ {
    int lc[N], rc[N];  // 左右儿子
    int val[N];        // 节点存储的值
    int key[N];        // 随机优先级（用于维持堆性质）
    int sz[N];         // 子树大小（用于求第 k 小）
    int root, idx;     // 根节点编号，当前已用节点数

    // 创建新节点，值为 v
    int new_node(int v) {
        val[++idx] = v;
        key[idx] = rand();  // 随机优先级
        sz[idx] = 1;
        lc[idx] = rc[idx] = 0;
        return idx;
    }

    // 更新子树大小
    void pushup(int p) { sz[p] = sz[lc[p]] + sz[rc[p]] + 1; }

    // 按值分裂：将树 p 分裂成两棵子树 x 和 y
    // x 中所有节点值 <= v，y 中所有节点值 > v
    void split(int p, int v, int& x, int& y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (val[p] <= v) {
            x = p;                      // 当前节点归入 x
            split(rc[p], v, rc[p], y);  // 递归分裂右子树
        } else {
            y = p;                      // 当前节点归入 y
            split(lc[p], v, x, lc[p]);  // 递归分裂左子树
        }
        pushup(p);  // 回溯时更新子树大小
    }

    // 合并两棵树 x 和 y，要求 x 中所有值 <= y 中所有值
    // 利用随机优先级维护堆性质（小根堆）
    int merge(int x, int y) {
        if (!x || !y) return x | y;  // 有一个为空，返回另一个
        if (key[x] < key[y]) {
            rc[x] = merge(rc[x], y);  // x 的优先级更小，作为根，合并其右子树与 y
            pushup(x);
            return x;
        } else {
            lc[y] = merge(x, lc[y]);  // y 的优先级更小，作为根，合并 x 与 y 的左子树
            pushup(y);
            return y;
        }
    }

    // 插入值 v
    void insert(int v) {
        int x, y;
        split(root, v, x, y);                    // 分裂出 <=v 和 >v 的两部分
        root = merge(merge(x, new_node(v)), y);  // 中间插入新节点，再合并回去
    }

    // 删除一个值为 v 的节点（只删一个）
    void erase(int v) {
        int x, y, z;
        split(root, v, x, z);   // x: <=v, z: >v
        split(x, v - 1, x, y);  // x: <v, y: ==v
        // y 中所有节点值都等于 v，我们删除其中一个（直接丢掉根，合并左右子树）
        y = merge(lc[y], rc[y]);       // 删除 y 的根节点（即一个 v）
        root = merge(merge(x, y), z);  // 合并回去
    }

    // 查询值 v 的排名（即有多少个数 < v，再 +1）
    int get_rank(int v) {
        int x, y;
        split(root, v - 1, x, y);  // x: <v
        int res = sz[x] + 1;       // 排名 = 小于 v 的个数 + 1
        root = merge(x, y);        // 合并回去
        return res;
    }

    // 查询第 k 小的数（k 从 1 开始）
    int get_kth(int p, int k) {
        if (!p) return -1;
        if (k <= sz[lc[p]])
            return get_kth(lc[p], k);  // 在左子树
        else if (k <= sz[lc[p]] + 1)
            return val[p];  // 当前节点
        else
            return get_kth(rc[p], k - sz[lc[p]] - 1);  // 在右子树
    }

    // 查询 v 的前驱（< v 的最大值）
    int get_pre(int v) {
        int x, y;
        split(root, v - 1, x, y);  // x: <v
        int p = x;
        while (p && rc[p]) p = rc[p];  // 在 x 中找最右节点（最大值）
        int res = p ? val[p] : -INF;   // 不存在则返回 -INF
        root = merge(x, y);            // 合并回去
        return res;
    }

    // 查询 v 的后继（> v 的最小值）
    int get_suc(int v) {
        int x, y;
        split(root, v, x, y);  // y: >v
        int p = y;
        while (p && lc[p]) p = lc[p];  // 在 y 中找最左节点（最小值）
        int res = p ? val[p] : INF;    // 不存在则返回 INF
        root = merge(x, y);            // 合并回去
        return res;
    }
    } T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x;
    cin >> x;
    int ans = x;  // 第一天的营业额直接计入答案（题目要求）
    T.insert(x);  // 插入第一个数

    // 从第二天开始处理
    for (int i = 2; i <= n; i++) {
        cin >> x;
        // 找到已插入数中，小于等于 x 的最大值（前驱）和大于等于 x 的最小值（后继）
        // 注意：get_pre(x+1) 等价于 <=x 的最大值（即前驱）
        //       get_suc(x-1) 等价于 >=x 的最小值（即后继）
        int pre = T.get_pre(x + 1);  // 实际上是 <=x 的最大值
        int suc = T.get_suc(x - 1);  // 实际上是 >=x 的最小值

        // 取两者中离 x 更近的，累加差值
        ans += min(x - pre, suc - x);
        T.insert(x);  // 插入当前值
    }

    cout << ans << endl;
    return 0;
}
