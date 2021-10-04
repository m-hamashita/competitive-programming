#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;
    char tmp;
    bool flag = true;
    rep(i, S.length()) {
        if (S[i] != T[i]) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        return 0;
    }
    rep(i, S.length() - 1) {
        tmp      = S[i + 1];
        S[i + 1] = S[i];
        S[i]     = tmp;
        flag     = true;
        rep(j, S.length()) {
            if (S[j] != T[j]) {
                flag = false;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
        tmp      = S[i + 1];
        S[i + 1] = S[i];
        S[i]     = tmp;
    }

    cout << "No" << endl;
    return 0;
}
