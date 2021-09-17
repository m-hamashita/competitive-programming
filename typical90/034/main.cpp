#include <algorithm>
#include <iostream>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, K;
    cin >> N >> K;
    ll A[N];
    rep(i, N) cin >> A[i];

    map<ll, ll> m;
    ll right  = 0;
    ll result = 0;
    for (ll left = 0; left < N; left++) {
        while (right < N && m.size() <= K) {
            m[A[right]]++;
            right++;
            if (m.size() <= K)
                result = max(result, right - left);
            else
                break;
        }
        m[A[left]]--;
        if (m[A[left]] == 0)
            m.erase(A[left]);
    }
    cout << result << endl;

    return 0;
}
