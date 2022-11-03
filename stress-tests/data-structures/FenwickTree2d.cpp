#include "../utilities/template.h"

#include "../../content/data-structures/FenwickTree2d.h"

int main() {
	rep(it,0,1000000) {
		int siz = 12;
		FenwickTree2D<ll> ft(siz);
		vector<tuple<int, int, int>> upd;
		int c = rand() % 20;
		rep(i,0,c-1) {
			upd.emplace_back(rand() % siz + 1, rand() % siz + 1, rand() % 10 - 5);
		}

		vector<vector<int>> grid(siz+1, vector<int>(siz+1)), sumto(siz+1, vector<int>(siz+1));
		for(auto &pa: upd)
			ft.fakeUpdate(get<0>(pa), get<1>(pa));
		ft.init();
		for(auto &pa: upd) {
			grid[get<0>(pa)][get<1>(pa)] += get<2>(pa);
			ft.update(get<0>(pa), get<1>(pa), get<2>(pa));
		}

		rep(i,0,siz) {
			rep(j,0,siz) {
				ll v = ft.query(i, j);
				if (i == 0 || j == 0) assert(v == 0);
				else {
					sumto[i][j] = grid[i][j] + sumto[i-1][j] + sumto[i][j-1] - sumto[i-1][j-1];
					assert(v == sumto[i][j]);
				}
			}
		}
	}
	cout<<"Tests passed!"<<endl;
}
