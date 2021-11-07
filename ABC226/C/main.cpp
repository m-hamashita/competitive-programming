#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

ll result = 0;
bool waza[200005];

vector<vector<ll>> v(200005);
vector<ll> t;
void dfs(ll value) {
    if (waza[value]) {
        return;
    }
    result += t[value];
    waza[value] = true;
    for (auto next : v[value]) {
        dfs(next);
    }
}

signed main() {
    ll N;
    cin >> N;
    ll T, K;
    ll tmp;
    rep(i, N) waza[i] = false;
    rep(i, N) {
        cin >> T >> K;
        t.push_back(T);
        rep(j, K) {
            cin >> tmp;
            v[i].push_back(tmp - 1);
        }
    }
    // if (v[N - 1].empty()) {
    //     cout << result << endl;
    //     return 0;
    // }
    result += t[N - 1];
    waza[N - 1] = true;
    for (auto value : v[N - 1]) {
        dfs(value);
    }

    cout << result << endl;

    return 0;
}
