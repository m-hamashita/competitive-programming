#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int N;
    int X, Y;
    cin >> N >> X >> Y;
    int A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];

    int dp[X + 7][Y + 7];
    rep(i, X + 7) {
        rep(j, Y + 7) {
            dp[i][j] = 100000;
        }
    }
    dp[0][0] = 0;
    int x1, y1;
    rep(k, N) {
        for (int i = X; i >= 0; i--) {
            for (int j = Y; j >= 0; j--) {
                x1 = min(X, i + A[k]);
                y1 = min(Y, j + B[k]);

                dp[x1][y1] = min(dp[x1][y1], dp[i][j] + 1);
            }
        }
    }
    // int result = 100000;
    // rep(i, 350) {
    //     rep(j, 350) {
    //         result = min(result, dp[X + i][Y + j]);
    //     }
    // }
    // rep(i, 15) {
    //     rep(j, 15) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[X][Y] >= 100000) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[X][Y] << endl;

    return 0;
}
