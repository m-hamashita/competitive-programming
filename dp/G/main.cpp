#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

int dp[100000];

// G を値渡しすると無限に時間がかかる
int dfs(vector<vector<int>> &G, int from) {
  if (dp[from] != -1)
    return dp[from];
  int result = 0;
  for (auto to : G[from]) {
    result = max(result, dfs(G, to) + 1);
  }
  dp[from] = result;
  return dp[from];
}

signed main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  rep(i, M) {
    int tmp_x, tmp_y;
    cin >> tmp_x >> tmp_y;
    G[tmp_x - 1].push_back(tmp_y - 1);
  }
  rep(i, 100000) dp[i] = -1;
  int result = 0;
  for (int i = 0; i < N; i++) {
    result = max(result, dfs(G, i));
  }

  // rep(i, N) cout << dp[i] << " ";
  // cout << endl;
  cout << result << endl;
  return 0;
}
