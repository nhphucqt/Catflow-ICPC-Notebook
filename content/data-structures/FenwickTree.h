/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[1] + a[1] + ... + a[i], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

template <typename T>
struct FenwickTree {
    int n;
    vector <T> tree;
    FenwickTree(int n) : n(n), tree(n + 1) {}
    void update(int i, T dif) {
        for ( ; i <= n; i += i & (-i)) tree[i] += dif;
    }
    T query(int i) {
        T res = 0;
        for ( ; i > 0; i -= i & (-i)) res += tree[i];
        return res;
    }
    int lower_bound(T sum) {
        int pos = 0;
        per (i, 31 - __builtin_clz(n), 0) {
            if (pos + (1 << i) <= n && tree[pos + (1 << i)] < sum)
                sum -= tree[pos += (1 << i)];
        }
        return pos + 1;
    }
};