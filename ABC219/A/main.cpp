#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    if (N >= 90) {
        cout << "expert" << endl;
    } else if (N >= 70) {
        cout << 90 - N << endl;
    } else if (N >= 40) {
        cout << 70 - N << endl;
    } else {
        cout << 40 - N << endl;
    }

    return 0;
}
