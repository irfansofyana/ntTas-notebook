bool comp(query a, query b){
	if (a.L / block == b.L/block)
		return a.R < b.R;
	return a.L/block < b.L/block;
}
 
void add(int x){
	cnt[x]++;
	if (cnt[x] == 1) distinct++;
}
 
void del(int x){
	cnt[x]--;
	if (cnt[x] == 0) distinct--;
}
 
int main(){
  OPTIMATION
  cin >> N;
  for (int i = 0; i < N; i++)
  	cin >> arr[i];
  block = (int)sqrt(N) + 1;
  cin >> Q;
  for (int i = 0; i < Q; i++){
  	int tl, tr;
  	cin >> tl >> tr;
  	tl--; tr--;
  	q[i].L = tl;
  	q[i].R = tr;
  	q[i].no = i;
  }
  sort(q, q+Q, comp);
  currL = 0;
  currR = 0;
  for (int i = 0; i < Q; i++){
  	int L = q[i].L;
  	int R = q[i].R;
  	while (currL < L) {
  		del(arr[currL]);
  		currL++;
  	}
  	while (currL > L){
  		add(arr[currL-1]);
  		currL--;
  	}
  	while (currR <= R) {
  		add(arr[currR]);
  		currR++;
  	}
  	while (currR > R+1){
  		del(arr[currR-1]);
  		currR--;
  	}
  	ans[q[i].no] = distinct;
  }
  for (int i = 0; i < Q; i++){
  	cout << ans[i] << '\n';
  }
  return 0;
} 