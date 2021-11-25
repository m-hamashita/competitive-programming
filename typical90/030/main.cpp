#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

int A[10000001];
signed main() {
    int N, K;
    cin >> N >> K;
    rep(i, N + 1) A[i] = 0;

    // Eratosthenes
    for (int i = 2; i <= N; i++) {
        if (A[i] == 0) {
            for (int j = i; j <= N; j += i) {
                A[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        if (A[i] >= K) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
