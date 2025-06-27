// https://www.luogu.com.cn/problem/P1127

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

string str[N], path[N];
int cnt, head[30], nxt[N], to[N], id[N], d[N], lans;
bool use[N];

void add_edge(int u, int v, int idx) {
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    id[cnt] = idx;
    // update degree
    d[u]++;
    d[v]--;
}

void dfs(int u) {  // 搜索函数
    for (int i = head[u]; i; i = nxt[i]) {
        if (!use[id[i]]) {      // 找到一条未使用的边
            use[id[i]] = true;  // 标记
            dfs(to[i]);
            lans++;  // 倒序存答案
            path[lans] = str[id[i]];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, st;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> str[i];  // 读入数据

    sort(str + 1, str + 1 + n);  // 排序
    // 先把存在的字典序最小的字母作为起点，如果是欧拉回路，则从这个起点切入
    st = str[1][0] - 'a' + 1;

    for (int hd, tl, i = n; i >= 1; i--) {
        hd = str[i][0] - 'a' + 1;                  // 首字母
        tl = str[i][str[i].size() - 1] - 'a' + 1;  // 尾字母
        add_edge(hd, tl, i);                       // 连边
    }

    for (int i = 1; i <= 26; i++)
        if (d[i] == 1) {
            st = i;
            break;
        }

    dfs(st);

    for (int i = 1; i <= n; i++)
        if (!use[i]) {
            cout << "***";
            return 0;
        }  // 如果没有使用所有边，无解

    for (int i = lans; i > 1; i--) cout << path[i] << ".";
    cout << path[1];  // 输出答案

    return 0;
}
