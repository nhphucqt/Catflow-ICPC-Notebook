#include "../utilities/template.h"

#include "../../content/data-structures/FenwickTree.h"

int main() {
	rep(it,0,100000) {
		int N = rand() % 10;
		FenwickTree<ll> fw(N);
		vector<int> t(N+1);
		rep(i,1,N) {
			int v = rand() % 3;
			fw.update(i, v);
			t[i] += v;
		}
		int q = rand() % 20;
		int ind = fw.lower_bound(q);
		int res = N+1, sum = 0;
		rep(i,1,N+1) {
			if (i != N+1) sum += t[i];
			if (sum >= q) {
				res = i;
				break;
			}
		}
		if (res != ind) {
			cerr << N << '\n';
			for (int i = 1; i <= N; ++i) {
				cerr << t[i] << ' ';
			} cerr << '\n';
			cerr << q << '\n';
			cerr << ' ' << res << ' ' << ind << '\n';
			assert(res == ind);
		}
	}
	cout<<"Tests passed!"<<endl;
}
