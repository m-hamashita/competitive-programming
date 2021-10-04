#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll A, B;
    vector<pair<ll, ll>> v;
    rep(i, N) {
        cin >> A >> B;
        v.push_back(make_pair(A, 1));
        v.push_back(make_pair(A + B, -1));
    }
    sort(v.begin(), v.end());
    // for (auto value : v) {
    //     cout << value.first << value.second << endl;
    // }
    ll login_num = 0;
    ll ans[N + 1];
    rep(i, N + 1) {
        ans[i] = 0;
    }
    ll before = -1;
    for (auto value : v) {
        if (before == -1) {
            before = value.first;
            login_num += value.second;
            continue;
        }
        ans[login_num] += (value.first - before);
        before = value.first;
        login_num += value.second;
    }
    rep(i, N) {
        if (i == N - 1) {
            cout << ans[i + 1] << endl;
        } else {
            cout << ans[i + 1] << " ";
        }
    }

    return 0;
}
