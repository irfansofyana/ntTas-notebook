const int maxn = 1e5 + 5;
vector<vi> AdjList, centroid;
int id[maxn],sz[maxn];

void dfsSizeSubtree(int node, int p) {
    sz[node] = 1;
    for(int i=0;i<AdjList[node].size();i++){
        int v = AdjList[node][i];
        if(v!=p) {
        dfsSizeSubtree(v, node);
            sz[node] += sz[v];
        }
    }
}

int findCentroid(int node, int ukuran, int label) {
    bool valid = true;
    for(int i=0;i<AdjList[node].size();i++){
        int v = AdjList[node][i];
        if(sz[v] > ukuran/2 && id[v] == -1) {
            //pindah ke centroid itu
            valid = false;
            sz[node] = ukuran-sz[v];
            sz[v] = ukuran;
            int cen = findCentroid(v, ukuran, label);
            id[cen] = label;
            return cen;
        }
    }
    if(valid) {
        id[node] = label;
        return node;
    }
    return -1;
}

int dfsCentroid(int node, int label) {
    int root = findCentroid(node, sz[node], label);
    id[root] = label
    for(int i=0;i<AdjList[root].size();i++){
        int v = AdjList[root][i];
        if(id[v] == -1){
            int cen = dfsCentroid(v, label+1);
            centroid[root].pb(cen); centroid[cen].pb(root);
        }
    }
    return root;
}

//MAIN
int n,i,j; scanf("%d",&n);
AdjList.assign(maxn, vi());
centroid.assign(maxn, vi());
for(i=0;i<n-1;i++){
    int a,b; scanf("%d %d",&a,&b);
    AdjList[a].pb(b); AdjList[b].pb(a);
}
dfsSizeSubtree(1, -1);
memset(id, -1, sizeof id);
int rootCentroid = dfsCentroid(1,0);