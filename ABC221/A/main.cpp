#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

long long lpow(long long x, long long y) {
    long long ret = 1;
    while (y) {

        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}
signed main() {
    ll A, B;
    cin >> A >> B;
    cout << lpow(32, abs(A - B)) << endl;

    return 0;
}
