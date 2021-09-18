#include <deque>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;
ll H, W;
ll rs, cs, rt, ct;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
char S[1005][1005];
ll dist[1005][1005][4];
struct state {
    ll x, y, dir;
};

signed main() {
    cin >> H >> W;
    cin >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;
    rep(i, H) rep(j, W) cin >> S[i][j];
    rep(i, H) rep(j, W) rep(k, 4) dist[i][j][k] = INF;
    deque<state> deq;
    for (int i = 0; i < 4; i++) {
        dist[rs][cs][i] = 0;
        deq.push_back({rs, cs, i});
    }
    while (!deq.empty()) {
        state u = deq.front();
        deq.pop_front();
        rep(i, 4) {
            ll tx   = u.x + dx[i];
            ll ty   = u.y + dy[i];
            ll cost = dist[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
            if (0 <= tx && tx < H && 0 <= ty && ty < W && S[tx][ty] == '.' && dist[tx][ty][i] > cost) {
                dist[tx][ty][i] = cost;
                if (u.dir != i)
                    deq.push_back({tx, ty, i});
                else
                    deq.push_front({tx, ty, i});
            }
        }
    }
    ll result = INF;
    rep(i, 4) {
        result = min(result, dist[rt][ct][i]);
    }
    cout << result << endl;

    return 0;
}
