#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, P;
    cin >> N >> P;
    ll A[N];
    ll count = 0;
    rep(i, N) cin >> A[i];
    rep(i, N) {
        if (A[i] < P)
            count++;
    }
    cout << count << endl;

    return 0;
}
