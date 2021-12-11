#include <bits/stdc++.h>

#include <algorithm>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, Q;
    cin >> N >> Q;
    vector<int> v;
    int tmp;
    rep(i, N) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ll x;
    rep(i, Q) {
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        auto pos = distance(v.begin(), it);
        cout << v.size() - int(pos) << endl;
    }

    return 0;
}
