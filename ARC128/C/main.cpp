#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    long double M, S;
    cin >> N >> M >> S;
    int A[N];
    rep(i, N) cin >> A[i];
    ll rev_ruiseki[N + 1];
    rev_ruiseki[N] = 0;
    rev_ruiseki[N - 1] = A[N - 1];
    rep(i, N - 1) {
        rev_ruiseki[N - i - 2] = rev_ruiseki[N - i - 1] + A[N - i - 2];
    }
    long double result = 0.0;
    ll max_index = 0;
    long double max_value = 0;
    ll left = N;
    long double x;
    rep(i, N) {
        rep(j, left) {
            if (j == 0) {
                max_value = rev_ruiseki[j] - rev_ruiseki[left];
                max_index = j;
                continue;
            }
            if ((max_value * (left - j)) < ((rev_ruiseki[j] - rev_ruiseki[left]) * (left - max_index))) {
                max_value = rev_ruiseki[j] - rev_ruiseki[left];
                max_index = j;
            }
        }

        bool ff = false;
        x = min(M, (S / (left - max_index)));
        if (M < (S / (left - max_index))) {
            ff = true;
        } else {
            ff = false;
        }
        result += ((rev_ruiseki[max_index] - rev_ruiseki[left]) * x);
        if (ff) {
            S -= (M * (left - max_index));
        } else {
            S = 0;
        }
        if (S <= 0) {
            break;
        }
        left = max_index;
    }
    cout << std::fixed;
    cout << setprecision(12) << result << endl;
    return 0;
}
