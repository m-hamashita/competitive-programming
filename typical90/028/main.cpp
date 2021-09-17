#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll A[1002][1002];
    rep(i, 1002) rep(j, 1002) A[i][j] = 0;
    ll lx, ly, rx, ry;
    rep(i, N) {
        cin >> lx >> ly >> rx >> ry;
        A[ly][lx]++;
        A[ry][rx]++;
        A[ly][rx]--;
        A[ry][lx]--;
    }

    rep(i, 1002) {
        ll tmp = 0;
        rep(j, 1002) {
            tmp += A[i][j];
            A[i][j] = tmp;
        }
    }

    rep(j, 1002) {
        ll tmp = 0;
        rep(i, 1002) {
            tmp += A[i][j];
            A[i][j] = tmp;
        }
    }

    ll result[N];
    rep(i, N) result[i] = 0;
    rep(i, 1001) {
        rep(j, 1001) {
            if (A[i][j] != 0)
                result[A[i][j] - 1]++;
        }
    }
    rep(i, N) {
        cout << result[i] << endl;
    }

    return 0;
}
