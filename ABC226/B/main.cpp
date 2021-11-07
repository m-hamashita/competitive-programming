#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    vector<vector<int>> v(N);
    int tmp;
    int L;
    rep(i, N) {
        cin >> L;
        rep(j, L) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int result = 0;
    for (auto value : v) {
        if (!value.empty())
            result++;
    }
    cout << result << endl;

    return 0;
}
