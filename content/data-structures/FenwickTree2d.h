/**
 * Author: Simon Lindholm
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate() before init()).
 * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
 * Status: stress-tested
 */
#pragma once

#include "FenwickTree.h"

template <typename T>
struct FenwickTree2D {
    int n;
    vector <vector <int> > node;
    vector <FenwickTree <T> > tree;
    FenwickTree2D(int n) : n(n), node(n + 1) {}
    void fakeUpdate(int x, int y) {
        for ( ; x <= n; x += x & -x) node[x].push_back(y);
    }
    void fakeQuery(int x, int y) {
        for ( ; x > 0; x -= x & -x) node[x].push_back(y);
    }
    void init() {
        tree.push_back(-1);
        rep (x, 1, n) {
            sort(node[x].begin(), node[x].end());
            node[x].resize(unique(all(node[x])) - node[x].begin());
            tree.push_back(sz(node[x]) + 1);
        }
    }
    int idx(int x, int y) { return upper_bound(all(node[x]), y) - node[x].begin(); }
    void update(int x, int y, T dif) {
        for ( ; x <= n; x += x & -x) tree[x].update(idx(x, y), dif);
    }
    T query(int x, int y) {
        T res = 0;
        for ( ; x > 0; x -= x & -x) res += tree[x].query(idx(x, y));
        return res;
    }
    // abc
};