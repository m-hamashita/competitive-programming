#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll A[N];
    bool B[N];
    rep(i, N) B[i] = false;
    rep(i, N) cin >> A[i];
    bool from_enable = false;
    bool to_enable   = false;
    ll from          = 0;
    ll from_value    = 0;
    ll to            = 0;
    ll to_value      = 0;
    for (int i = 0; i < N; i++) {
        to = i;
        if (!(from_enable == true)) {
            from        = i;
            from_value  = A[i];
            from_enable = true;
            continue;
        }
        if (!(to_enable == true) && from_value >= A[i]) {
            to_enable = true;
            to_value  = A[i];
            continue;
        }
        if (!(to_enable == true) && from_value < A[i]) {
            from_value = A[i];
            from       = i;
            continue;
        }
        if (to_value <= A[i]) {
            B[from]    = true;
            B[i - 1]   = true;
            to_enable  = false;
            from_value = A[i];
            from       = i;
        }
        to_value = A[i];
    }
    if (from_enable == true && to_enable == true) {
        B[from] = true;
        B[to]   = true;
    }

    rep(i, N) {
        if (i == N - 1) {
            if (B[i]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (B[i]) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
    }

    return 0;
}
