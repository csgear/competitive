
// https://cses.fi/problemset/task/2072

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    int prio, size;
    Node *l, *r;

    Node(char c) : val(c), prio(rand()), size(1), l(nullptr), r(nullptr) {}
};

int getSize(Node* t) { return t ? t->size : 0; }

void updSize(Node* t) {
    if (t) t->size = 1 + getSize(t->l) + getSize(t->r);
}

// Split treap 't' into 'l' and 'r'
// 'l' gets the first 'pos' nodes, 'r' gets the rest
void split(Node* t, int pos, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    int leftSize = getSize(t->l);
    if (pos <= leftSize) {
        split(t->l, pos, l, t->l);
        r = t;
    } else {
        split(t->r, pos - leftSize - 1, t->r, r);
        l = t;
    }
    updSize(t);
}

// Merge two treaps 'l' and 'r', returns root
Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prio > r->prio) {
        l->r = merge(l->r, r);
        updSize(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        updSize(r);
        return r;
    }
}

// Insert a character at the end
Node* insert(Node* t, char c) {
    Node* newNode = new Node(c);
    return merge(t, newNode);
}

// In-order traversal to print the string
void inorder(Node* t) {
    if (!t) return;
    inorder(t->l);
    cout << t->val;
    inorder(t->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    // Build initial treap
    Node* root = nullptr;
    for (char c : s) {
        root = insert(root, c);
    }

    // Process m operations
    while (m--) {
        int a, b;
        cin >> a >> b;
        // Convert to 0-based indexing for split
        // We want to extract [a-1, b-1] (0-based)
        Node *left, *mid, *right;

        // Step 1: split at a-1 → [0, a-2] and [a-1, end]
        split(root, a - 1, left, mid);

        // Step 2: split mid at (b - a + 1) → [a-1, b-1] and [b, end]
        split(mid, b - a + 1, mid, right);

        // Step 3: merge as left + right + mid
        root = merge(merge(left, right), mid);
    }

    // Output final string
    inorder(root);
    cout << '\n';

    return 0;
}
