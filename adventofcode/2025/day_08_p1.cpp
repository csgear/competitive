#include <bits/stdc++.h>
using namespace std;

using Point = struct {
    int x, y, z;
} ;

vector<Point> pts ;

// Union-Find structure
class UnionFind {
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        // union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;

        components--;
        return true;
    }

    int getComponents() { return components; }
};

// Calculate squared distance (to avoid floating point)
long long dist2(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}

int main() {
    int x, y, z;
    while(scanf("%d,%d,%d", &x, &y, &z) == 3) {
        pts.push_back({x, y, z});
    }

    int n = pts.size();
    UnionFind uf(n);

    // Create all edges with distances (like Kruskal's algorithm)
    vector<tuple<long long, int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({dist2(pts[i], pts[j]), i, j});
        }
    }

    // Sort by distance
    sort(edges.begin(), edges.end());

    // Perform up to 1000 unions (connect 1000 closest pairs)
    int operations = 0;
    const int MAX_OPS = 1000;

    for (auto [d, i, j] : edges) {
        uf.unite(i, j);
        operations++;
        if (operations >= MAX_OPS) break;
    }

    // Record component IDs for each point
    map<int, vector<int>> components;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);
        components[root].push_back(i);
    }

    vector<int> component_sizes;
    for (auto& [root, members] : components) {
        component_sizes.push_back(members.size());
    }

    sort(component_sizes.rbegin(), component_sizes.rend());

    if (component_sizes.size() >= 3) {
        long long product = (long long)component_sizes[0] * component_sizes[1] * component_sizes[2];
        cout << product << endl;
    }

    return 0 ;
}
