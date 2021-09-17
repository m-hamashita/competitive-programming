#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

ll c = 0;
ll N;
vector<ll> result;
vector<vector<ll>> v(100005);
bool flag[100005];
void dfs(ll i, ll num) {
    flag[i] = true;
    if (num % 2 == 0 && c < N / 2) {
        c++;
        result.push_back(i + 1);
    }
    for (auto value : v[i]) {
        if (flag[value])
            continue;
        dfs(value, num + 1);
    }
}

signed main() {
    cin >> N;

    ll a, b;
    rep(i, N - 1) {
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rep(i, 100005) flag[i] = false;

    dfs(0, 0);
    // 偶奇の関係で，N/2 を超えないパターンが発生するので
    if (c != N / 2) {
        c                      = 0;
        rep(i, 100005) flag[i] = false;
        result.clear();
        dfs(v[0][0], 0);  // 偶奇をずらす
    }
    for (int i = 0; i < result.size(); i++) {
        if (i == 0) {
            cout << result[i];
            continue;
        }
        cout << " " << result[i];
    }
    cout << endl;

    return 0;
}
