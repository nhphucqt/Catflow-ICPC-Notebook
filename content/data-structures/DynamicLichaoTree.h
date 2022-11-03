/**
 * Author: hieplpvip
 * Date: 2020-10-17
 * License: CC0
 * Source: own work
 * Description: Container where you can add segment of the form ax+b, and query maximum/minimum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

template <typename T, T minX, T maxX, T defVal, bool maximum>
struct DynamicLiChaoTree {
    struct Line {
        T a, b;
        Line(T a = 0, T b = maximum ? defVal : -defVal) : a(a), b(b) {}
        T f(T x) { return a * x + b; }
    };
    struct Node {
        Line ln;
        Node *lc, *rc;
        Node(Line ln = Line()) : ln(ln), lc(nullptr), rc(nullptr) {}
    } *root;
    DynamicLiChaoTree() { root = new Node(); }  
    void update(Node *cur, T u, T v, T l, T r, Line nw) {
        #define newNode(x) if (!x) x = new Node()
        if (r < u || v < l) return;
        int m = (u + v) / 2;
        if (l <= u && v <= r) {
            if (cur->ln.f(l) >= nw.f(l)) swap(cur->ln, nw);
            if (cur->ln.f(r) <= nw.f(r)) return void(cur->ln = nw);

            if (nw.f(m) >= cur->ln.f(m)) {
                newNode(cur->rc);
                update(cur->rc, m + 1, v, l, r, cur->ln);
                cur->ln = nw;
            } else {
                newNode(cur->lc);
                update(cur->lc, u, m, l, r, nw);
            }
        } else {
            newNode(cur->lc); newNode(cur->rc);
            update(cur->lc, l, m, u, v, nw);
            update(cur->rc, m, r, u, v, nw);
        }
        #undef newNode
    }
    void insert(T a, T b, T l = minX, T r = maxX) {
        if (!maximum) a = -a, b = -b;
        update(root, minX, maxX, l, r, Line(a, b));
    }
    T query(T x) {
        Node *cur = root;
        T res = cur->ln.f(x), u = minX, v = maxX;
        while (cur) {
            maximize(res, cur->ln.f(x));
            T m = (u + v) / 2;
            if (x <= m) cur = cur->lc, v = m;
            else cur = cur->rc, u = m + 1;
        }
        return maximum ? res : -res;
    }
};