#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
 
using namespace std;
 
typedef long long LL;
const int MAXN = 132000;
 
struct data {
  LL sum;
  LL delayedAdd;
};
 
data sTree[2*MAXN];
 
LL GET(int id, int l, int r) {
  return sTree[id].sum + sTree[id].delayedAdd*(r-l+1);
}
 
void LAZY_UPDATE(int id, int delta) {
  sTree[id].delayedAdd += delta;
}
 
void PROPAGATE(int id) {
  LAZY_UPDATE(2*id+1, sTree[id].delayedAdd);
  LAZY_UPDATE(2*id+2, sTree[id].delayedAdd);
 
  sTree[id].delayedAdd = 0;
}
 
void MERGE(int id, int l, int m, int r) {
  sTree[id].sum = GET(2*id+1, l, m) + GET(2*id+2, m+1, r);
}
 
void update(int id, int l, int r, int xa, int xb, int delta) {
  if ((xa <= l) && (r <= xb)) {
    LAZY_UPDATE(id, delta);
  } else {
    int m = (l + r)/2;
 
    PROPAGATE(id);
 
    if (xa <= m) update(2*id+1, l, m, xa, xb, delta);
    if (xb >  m) update(2*id+2, m+1, r, xa, xb, delta);
 
    MERGE(id, l, m, r);
  }
}
 
LL query(int id, int l, int r, int xa, int xb) {
  if ((xa <= l) && (r <= xb)) {
    return GET(id,l,r);
  }else{
    int m = (l + r)/2;
 
    PROPAGATE(id);
 
    LL ret = 0;
    if (xa <= m) ret += query(2*id+1, l, m, xa, xb);
    if (xb >  m) ret += query(2*id+2, m+1, r, xa, xb);
 
    MERGE(id, l, m, r);
    return ret;
  }
}
 
int main() {
  int nTc;
  scanf("%d", &nTc);
 
  for (int jt = 0; jt < nTc; jt++) {
    int N, Q;
    scanf("%d%d", &N, &Q);
 
    // Reset
    for (int i = 0; i < 2*MAXN; i++) {
      sTree[i].sum = 0;
      sTree[i].delayedAdd = 0;
    }
 
    for (int i = 0; i < Q; i++) {
      int a, b, delta, jq;
      scanf("%d", &jq);
 
      if (jq == 0) {
        scanf("%d%d%d", &a, &b, &delta);
        update(0, 0, N-1, a-1, b-1, delta);
      } else {
        scanf("%d%d", &a,&b);
        printf("%lld\n", query(0, 0, N-1, a-1, b-1));
      }
    }
  }
 
  return 0;
}
