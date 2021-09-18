#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const long long MOD = 100000;

using namespace std;
ll visit[100000];

ll calc(ll num) {
    ll z = num;
    while (num) {
        z += (num % 10);
        num /= 10;
    }
    return z % MOD;
}

signed main() {
    ll N, K;
    cin >> N >> K;
    ll diff;
    rep(i, 100000) visit[i] = INF;

    rep(i, 100001) {
        if (i == K) {
            cout << N << endl;
            return 0;
        }
        if (visit[N] != INF) {
            diff = i - visit[N];
            break;
        } else {
            visit[N] = i;
        }
        N = calc(N);
    }
    diff = (K - visit[N]) % diff;
    rep(i, diff) {
        N = calc(N);
    }
    cout << N << endl;

    return 0;
}
