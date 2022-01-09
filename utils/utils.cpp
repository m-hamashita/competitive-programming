#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
const int MOD = 1000000007;
const int MAX = 1000;

long long fac[MAX], finv[MAX], inv[MAX];

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long lpow(long long x, long long y) {
    long long ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}

long long pow_mod(long long x, long long y, long long MOD) {
    long long ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}

// a^{-1} mod を計算する (フェルマーの小定理)
// long long modinv(long long a, long long mod) {
//     return pow_mod(a, mod - 2, mod);
// }

// 素数じゃなくても良い
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

long long conbination(long long n, long long r, int MOD) {
    long long fact_r = 1;
    for (int i = 1; i <= r; i++) {
        fact_r *= i;
        fact_r = fact_r % MOD;
    }
    // fact_r の逆元を求める
    // long long result = pow_mod(fact_r, MOD-2, MOD);
    long long result = modinv(fact_r, MOD);
    for (int i = n - r + 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// UnionFind Tree
struct UnionFind {
    vector<int> par, siz;

    // initialize
    UnionFind(int n) : par(n, -1), siz(n, 1) {
    }

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    int issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

signed main() {
    cout << 1999999 << "'s inv: " << modinv(1999999, MOD) << endl;
    cout << 1999999 * modinv(1999999, MOD) % MOD << endl;
    return 0;
}
