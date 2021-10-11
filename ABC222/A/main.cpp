#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    string N;
    cin >> N;
    for (int i = 0; i < 4 - N.length(); i++) {
        cout << "0";
    }
    cout << N << endl;

    return 0;
}
