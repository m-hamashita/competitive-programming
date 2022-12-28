#include <bits/stdc++.h>

#include <cmath>
#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

signed main() {
    double N, K;
    cin >> N >> K;
    int a;
    double probability = 0.0;
    double dice = 1.0 / double(N);
    int x;
    rep(i, N) {
        a = i + 1;
        if (K <= a) {
            probability += dice;
        } else {
            x = (K + a - 1) / a;
            x = double(ceil(log2(x)));
            probability += dice * pow(1.0 / 2.0, x);
        }
    }
    cout << fixed << setprecision(12) << probability << endl;

    return 0;
}
