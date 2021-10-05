#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;
vector<int> v[100005];
vector<int> iv[100005];
bool used[100005];
vector<int> nodes;
ll c = 0;

void dfs(int i) {
    used[i] = true;
    for (int value : v[i]) {
        if (used[value] == false)
            dfs(value);
    }
    nodes.push_back(i);
}

void idfs(int i) {
    used[i] = true;
    c++;
    for (int value : iv[i]) {
        if (used[value] == false)
            idfs(value);
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    int A, B;
    ll result = 0;
    rep(i, M) {
        cin >> A >> B;
        A--;
        B--;
        v[A].push_back(B);
        iv[B].push_back(A);
    }
    rep(i, N) used[i] = false;

    // トポロジカルソート
    rep(i, N) {
        if (used[i] == false)
            dfs(i);
    }
    reverse(nodes.begin(), nodes.end());

    rep(i, N) used[i] = false;

    // 逆からもやって，強連結成分の数を取得→NC2 を足す
    for (int i : nodes) {
        if (used[i] == true)
            continue;
        c = 0;
        idfs(i);
        result += c * (c - 1LL) / 2LL;  // _NC_2
    }

    cout << result << endl;

    return 0;
}
