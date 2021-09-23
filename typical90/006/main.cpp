#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;
typedef pair<char, int> p;

struct Compare {
    constexpr bool operator()(pair<char, int> const& a, pair<char, int> const& b) const noexcept {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    }
};

signed main() {
    ll N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    priority_queue<p, vector<p>, Compare> pq;
    rep(i, N - K) {
        pq.push(make_pair(S[i], i));
    }

    pair<char, int> tmp;
    string result = "";
    ll left       = -1;

    for (int i = 0; i < K; i++) {
        pq.push(make_pair(S[N - K + i], N - K + i));
        while (1) {
            tmp = pq.top();
            pq.pop();
            if (tmp.second > left)
                break;
        }
        result += tmp.first;
        left = tmp.second;
    }
    cout << result << endl;

    return 0;
}
