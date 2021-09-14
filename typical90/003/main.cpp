#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

vector<vector<ll>> v(100005);
bool flag[100005];
ll length[100005];

// これ dfs では？(木だから助かってる)
void bfs(ll u, ll len) {
    if (flag[u])
        return;
    flag[u] = true;
    for (auto value : v[u]) {
        bfs(value, len + 1);
    }
    length[u] = len;
}

signed main() {
    ll N;
    cin >> N;
    ll a, b;
    rep(i, N) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    rep(i, N) {
        flag[i] = false;
    }

    // 適当なところから bfs して最長を見つける．見つけた最長のノードからスタートして最長を見つける
    bfs(0, 0);
    ll max_length = 0;
    ll max_node   = 0;

    // 最長を見つける処理
    rep(i, N) {
        if (max_length < length[i]) {
            max_length = length[i];
            max_node   = i;
        }
    }

    // もう一度探索するため，flag を false にする
    rep(i, N) {
        flag[i] = false;
    }
    // 最長からスタートする
    bfs(max_node, 0);
    max_length = 0;

    // 真の最長経路を見つける
    rep(i, N) {
        max_length = max(max_length, length[i]);
    }

    cout << max_length + 1 << endl;
    return 0;
}
