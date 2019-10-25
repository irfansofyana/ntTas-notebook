struct Node {
    int cnt;
    Node *left, *right;
    Node(int cnt, Node *left, Node *right) {
        this->cnt = cnt;
        this->left = left;
        this->right = right;
    }
    Node *insert(int l, int r, int k) {
        if (!(l <= k && k <= r)) r
            return this;
        Node *node = new 
            Node(this->cnt + 1, this->left, this->right);
        if (l == r) return node;
        int m = (l + r) / 2;
        node->left = node->left->insert(l, m, k);
        node->right = node->right->insert(m + 1, r, k);
        return node;
    }

    static int query(Node *a, Node *b, int l, int r, int k) {
        if (l == r) return l;
        int m = (l + r) / 2;
        int cnt = b->left->cnt - a->left->cnt;
        if (cnt >= k + 1)
        return query(a->left, b->left, l, m, k);
        return query(a->right, b->right, m + 1, r, k - cnt);
    }
};

// MAIN
int n, m;scanf("%d %d", &n, &m);
map<int, int> M, RM;
int a[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    M[a[i]];
}
int cntr = 0;
for (auto it = M.begin(); it != M.end(); it++) {
    M[it->first] = cntr;
    RM[cntr] = it->first;
    cntr++;
}
cntr--;
Node *null = new Node(0, NULL, NULL);
null->left = null, null->right = null;
Node *roots[n];
for (int i = 0; i < n; i++)
    roots[i] = (i == 0 ? null : roots[i - 1])->insert(0, cntr, M[a[i]]);
int u, v, k;
while (m--) {
    scanf("%d %d %d", &u, &v, &k);u--, v--, k--;
    Node *a = (u == 0 ? null : roots[u - 1]);
    Node *b = roots[v];
    int res = Node::query(a, b, 0, cntr, k);
    printf("%d\n", RM[res]);
}