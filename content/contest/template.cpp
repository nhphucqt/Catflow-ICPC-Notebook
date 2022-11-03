#include <bits/stdc++.h>
using namespace std;

//#define int long long
//#define double long double
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, r, l) for (int i = (int)(r); i >= (int)(l); i--)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template <typename T> bool minimize(T &a, const T &b) { return a > b ? a = b, true : false; }
template <typename T> bool maximize(T &a, const T &b) { return a < b ? a = b, true : false; }

const string file = "";

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef MANIWA
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
    #endif // MANIWA
    return 0;
}