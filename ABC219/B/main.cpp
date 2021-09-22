#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    string S1, S2, S3, T;
    cin >> S1 >> S2 >> S3 >> T;
    string result = "";
    for (int i = 0; i < T.size(); i++) {
        if (T[i] == '1') {
            result += S1;
        }
        if (T[i] == '2') {
            result += S2;
        }
        if (T[i] == '3') {
            result += S3;
        }
    }
    cout << result << endl;

    return 0;
}
