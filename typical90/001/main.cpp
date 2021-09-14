#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, K, L;
    cin >> N >> L >> K;
    ll A[N];
    rep(i, N) { cin >> A[i]; }
    ll left  = 0;
    ll right = L;
    ll mid;
    // 最低でも tmp cm あるように切った時に K 個あるかどうか
    // K 個以上ある場合 => tmp cm 以上 である
    // K 個未満の場合   => tmp cm 未満 である
    while (right - left > 1) {
        mid           = left + (right - left) / 2;
        ll count      = 0;
        ll sum_length = 0;
        ll before     = 0;
        for (int i = 0; i < N; i++) {
            sum_length += A[i] - before;
            if (sum_length >= mid) {
                count++;
                sum_length = 0;
            }
            before = A[i];
        }
        sum_length += L - before;
        if (sum_length >= mid)
            count++;
        if (count >= K + 1)
            left = mid;
        else
            right = mid;
    }
    cout << left << endl;

    return 0;
}
