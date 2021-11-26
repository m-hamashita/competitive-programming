#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll t, N;
    cin >> t;
    rep(j, t) {
        cin >> N;
        int b[N];
        int p[N];
        int dist[N];
        int weight[N];
        bool flag[N];
        rep(i, N) {
            flag[i] = false;
        }
        rep(i, N) {
            cin >> b[i];
            b[i]--;
        }
        rep(i, N) {
            cin >> p[i];
            p[i]--;
        }
        bool output = true;
        if (b[p[0]] != b[p[0]]) {  // p[0] が root でないとき
            cout << -1 << endl;
            continue;
        }
        flag[p[0]] = true;
        dist[p[0]] = 0;
        for (int i = 1; i < N; i++) {
            if (!flag[b[p[i]]]) {  // 親がまだ未訪問の場合、解が存在しない
                output = false;
                break;
            }
            flag[p[i]] = true;
            dist[p[i]] = dist[p[i - 1]] + 1;
        }
        if (!output) {
            cout << -1 << endl;
            continue;
        }
        rep(i, N) {
            weight[i] = dist[i] - dist[b[i]];  // 親と子の間の距離(weight)
        }
        rep(i, N) {
            if (i == N - 1) {
                cout << weight[i] << endl;
            } else {
                cout << weight[i] << " ";
            }
        }
    }

    return 0;
}
