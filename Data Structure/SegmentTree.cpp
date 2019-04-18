/* RMQ */
class SegmentTree{
	private:
		vector<int> st, A;
		int n;
	public:
		int left(int p){
			return (p << 1);
		}
		int right(int p){
			return (p << 1) + 1;
		}
		void build(int p, int L, int R){
			if (L == r){
				st[p] = L;
			}else {
				int mid = (L + R) >> 1;
				build(left(p), L, mid);
				build(right(p), mid+1, r);
				int p1 = st[left(p)];
				int p2 = st[right(p)];
				st[p] = (A[p1] <= A[p2] ? p1 : p2);
			}
		}

		int rmq(int p, int L, int R, int i,int j){
			if (i > R || j < L) return -1; //outside range
			if (L >= i && R <= j) return st[p];
			int mid = (L + R) >> 1;
			int p1 = rmq(left(p), L, mid, i, j);
			int p2 = rmq(left(p), mid+1, R, i, j);
			if (p1 == -1) return p2;
			if (p2 == -1) return p1;
			return (A[p1] <= A[p2] ? p1 : p2);
		}

};