#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;
long long lgcd(long long a, long long b) {  // 2つの場合の最大公約数
    if (b == 0) {
        return a;
    } else {
        return lgcd(b, a % b);
    }
}

signed main() {
    ll N;
    cin >> N;
    ll x[N], y[N];
    rep(i, N) {
        cin >> x[i] >> y[i];
    }
    vector<pair<ll, ll>> v;
    ll xdiff, ydiff;
    ll kouyaku;
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            xdiff = x[i] - x[j];
            ydiff = y[i] - y[j];
            kouyaku = lgcd(xdiff, ydiff);
            v.push_back(make_pair(xdiff / kouyaku, ydiff / kouyaku));
            v.push_back(make_pair(xdiff / kouyaku * (-1), ydiff / kouyaku * (-1)));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // int result = 0;
    // for (auto value : v) {
    //     if (!value.empty())
    //         result++;
    // }
    cout << v.size() << endl;

    return 0;
}
