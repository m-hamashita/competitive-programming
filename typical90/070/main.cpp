#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll X[N];
    ll Y[N];
    rep(i, N) {
        cin >> X[i];
        cin >> Y[i];
    }
    sort(X, X + N);
    sort(Y, Y + N);
    ll x_median = X[(N + 1) / 2 - 1];
    ll y_median = Y[(N + 1) / 2 - 1];

    ll result = 0;
    rep(i, N) {
        result += abs(x_median - X[i]);
        result += abs(y_median - Y[i]);
    }
    cout << result << endl;

    return 0;
}
