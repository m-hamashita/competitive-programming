#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    string S[N];
    rep(i, N) cin >> S[i];
    map<string, ll> mp;
    rep(i, N) {
        mp[S[i]]++;
    }
    string max_str = "";
    ll max_num = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second > max_num) {
            max_str = itr->first;
            max_num = itr->second;
        }
    }
    cout << max_str << endl;

    return 0;
}
