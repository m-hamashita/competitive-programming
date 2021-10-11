#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, M;
    cin >> N >> M;
    char A[2 * N][M];
    rep(i, 2 * N) {
        rep(j, M) {
            cin >> A[i][j];
        }
    }
    vector<pair<ll, ll>> v;
    rep(i, 2 * N) {
        v.push_back(make_pair(0, i));
    }
    sort(v.begin(), v.end());

    rep(i, M) {
        rep(j, N) {
            ll left  = v[2 * j].second;
            ll right = v[2 * j + 1].second;
            if ((A[left][i] == 'G' && A[right][i] == 'C') || (A[left][i] == 'C' && A[right][i] == 'P')
                || (A[left][i] == 'P' && A[right][i] == 'G')) {
                v[2 * j].first--;
            } else if (A[left][i] == A[right][i]) {
                continue;
            } else {
                v[2 * j + 1].first--;
            }
        }
        sort(v.begin(), v.end());
    }
    rep(i, 2 * N) {
        cout << v[i].second + 1 << endl;
    }

    return 0;
}
