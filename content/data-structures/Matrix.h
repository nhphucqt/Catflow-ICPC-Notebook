/**
 * Author: Ulf Lundstrom
 * Date: 2009-08-03
 * License: CC0
 * Source: My head
 * Description: Basic operations on square matrices.
 * Usage: Matrix<int, 3> A;
 *  A.d = {{{{1,2,3}}, {{4,5,6}}, {{7,8,9}}}};
 *  vector<int> vec = {1,2,3};
 *  vec = (A^N) * vec;
 * Status: tested
 */
#pragma once

struct Matrix {
    int n, m;
    int a[101][101];
    Matrix(int n, int m) : n(n), m(m) {
        rep (i, 1, n) rep (j, 1, m) a[i][j] = 0;
    }
    Matrix() {}
    static Matrix identity(int n) {
        Matrix res(n, n);
        rep (i, 1, n) res.a[i][i] = 1;
        return res;
    }
    Matrix operator * (const Matrix &oth) const {
        assert(m == oth.n);
        Matrix res(n, oth.m);
        rep (i, 1, n) rep (j, 1, oth.m) rep (k, 1, m)
            (res.a[i][j] += a[i][k] * (ll)oth.a[k][j] % mod) %= mod;
        return res;
    }
    Matrix &operator *= (const Matrix &oth) { return *this = *this * oth; }
    Matrix pow(ll exp) {
        assert(n == m);
        Matrix base = *this, res = identity(n);
        for ( ; exp; exp >>= 1, base *= base) if (exp & 1) res *= base;
        return res;
    }
};
