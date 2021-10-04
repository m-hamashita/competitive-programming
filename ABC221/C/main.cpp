#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    string S;
    cin >> S;
    char N[S.length()];
    rep(i, S.length()) {
        N[i] = S[i];
    }
    sort(N, N + S.length());
    // rep(i, S.length()) {
    //     cout << N[i];
    // }
    string X = "";
    string Y = "";
    rep(i, S.length()) {
        if (X.length() != 0) {
            if (Y.length() != 0) {
                if (stoll(X) < stoll(Y)) {
                    X += N[S.length() - i - 1];
                } else {
                    Y += N[S.length() - i - 1];
                }
            } else {
                Y += N[S.length() - i - 1];
            }
        } else {

            X += N[S.length() - i - 1];
        }
    }
    cout << stoll(X) * stoll(Y) << endl;

    return 0;
}
