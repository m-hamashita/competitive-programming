#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

int H, W;
char c[16][16];
bool flag[16][16];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int sx, int sy, int rx, int ry) {
    // start に戻ってきたら
    if (sx == rx && sy == ry && flag[rx][ry] == true)
        return 0;
    flag[rx][ry] = true;
    int ret      = -100;
    rep(i, 4) {
        int nextX = rx + dx[i];
        int nextY = ry + dy[i];
        if (nextX < 0 || nextX > H - 1 || nextY < 0 || nextY > W - 1)
            continue;
        if (c[nextX][nextY] == '#')
            continue;
        // start と異なるかつ true だったら見ない( start ならば true でも許す)
        if (flag[nextX][nextY] == true && (sx != nextX || sy != nextY))
            continue;
        ret = max(ret, dfs(sx, sy, nextX, nextY) + 1);
    }
    flag[rx][ry] = false;
    return ret;
}
signed main() {
    rep(i, 16) rep(j, 16) {
        flag[i][j] = false;
        c[i][j]    = '#';
    }
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> c[i][j];
    int result = 0;
    rep(i, H) {
        rep(j, W) {
            result = max(result, dfs(i, j, i, j));
        }
    }
    if (result < 3) {
        cout << -1 << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}
