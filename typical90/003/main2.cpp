#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

vector<vector<ll>> v(100005);
ll length[100005];
queue<ll> q;

void bfs(ll u, ll len) {
    q.push(u);
    length[u] = 0;

    while (!q.empty()) {
        ll from = q.front();
        q.pop();
        for (auto to : v[from]) {
            // bfs だと最初に見つけたものが必ず最短経路になるため
            if (length[to] == INF) {
                length[to] = length[from] + 1;
                q.push(to);
            }
        }
    }
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
        length[i] = INF;
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

    // もう一度探索するため，length を INF にする
    rep(i, N) {
        length[i] = INF;
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
