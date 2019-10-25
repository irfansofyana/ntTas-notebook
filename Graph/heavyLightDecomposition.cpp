const int maxn = 1e4 + 4;
vector<vii> AdjList;
vi parent, depth, heavy, head, pos;
vector<vi> indexx;
int curPos,sz[maxn],w[maxn],tempW[maxn],akhir[maxn];

int dfs(int node, int p, int dalam) {
    sz[node] = 1;
    int maks = 0;
    depth[node] = dalam;
    for(int i=0;i<AdjList[node].size();i++){
        ii v = AdjList[node][i];
        int tetangga = v.first, berat = v.second;
        if(tetangga != p) {
            int idx = indexx[node][i];
            akhir[idx] = tetangga;
            parent[tetangga] = node;
            int ukuranTetangga = dfs(tetangga, node, dalam+1);
            sz[node] += ukuranTetangga;
            tempW[tetangga] = berat;
            if(maks < ukuranTetangga) {
                maks = ukuranTetangga;
                heavy[node] = tetangga;
            }
        }
    }
    return sz[node];
}

void decompose(int node, int h) {
    head[node] = h, pos[node] = curPos++;
    if(heavy[node] != -1)
    decompose(heavy[node], h);
    for(int i=0;i<AdjList[node].size();i++){
        ii v = AdjList[node][i];
        int tetangga = v.first, berat = v.second;
        if(parent[node] != tetangga && heavy[node] != tetangga)
            decompose(tetangga, tetangga);
    }
}

void assignWeight(int n) {
    for(int i=1;i<=n;i++){
        int posisi = pos[i];
        w[posisi] = tempW[i];
    }
}

int st[4*maxn];
int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}

void build(int node, int l, int r) {
    if(l == r) {
        st[node] = w[l];
        return;
    }
    int mid = (l+r)/2;
    build(left(node), l, mid);
    build(right(node), mid+1, r);
    st[node] = max(st[left(node)], st[right(node)]);
}

int query(int node, int l, int r, int i, int j) {
    if(j < l || r < i) {return -inf;}
    if(i <= l && r <= j){return st[node];}
    int mid = (l+r)/2;
    int ans1 = query(left(node), l, mid, i, j);
    int ans2 = query(right(node), mid+1, r, i, j);
    return max(ans1, ans2);
}

void update(int node, int l, int r, int idx, int val) {
    if(r < idx || l > idx){return;}
    if(idx == r && idx == l){
        st[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(left(node), l, mid, idx, val);
    update(right(node), mid+1, r, idx, val);
    st[node] = max(st[left(node)], st[right(node)]);
}

void updateQuery(int idx, int val) {
    int nodeAkhir = akhir[idx];
    update(1,1,curPos,pos[nodeAkhir], val);
}

int jawabQuery(int a, int b) {
    if(a == b) return 0;
    int ans = -inf;
    for(; head[a] != head[b]; b = parent[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a,b);
        int cur = query(1,1,curPos,pos[head[b]], pos[b]);
        ans = max(ans, cur);
    }
    if(depth[a] > depth[b]) swap(a,b);
    int cur = query(1,1,curPos,pos[a]+1, pos[b]);
    ans = max(ans, cur);
    return ans;
}

void preprocess() {
    int n = AdjList.size();
    parent = vi(n+1);
    depth = vi(n+1);
    heavy = vi(n+1, -1);
    head = vi(n+1);
    pos = vi(n+1);
    curPos = 1;
    dfs(1, -1,0);
    decompose(1,1);
    assignWeight(n);
    build(1,1,curPos);
}

// MAIN
// INPUT
preprocess()