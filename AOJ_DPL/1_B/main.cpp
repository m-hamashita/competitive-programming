#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int dp[11005];
int select[11005][105];

int knapsack(vector<int> v, vector<int> w, int N, int W){
  int tmp;
  rep(i, W+1){
    tmp = -1;
    if (i>0) {
      if (dp[i] < dp[i-1]){
        dp[i] = max(dp[i], dp[i-1]);
        rep(k, 105){
          select[i][k] = select[i-1][k];
        }
      }
    }
    rep(j, N){
      if (select[i][j]==0){
        if (dp[i]+v[j] > dp[i+w[j]]){
          dp[i+w[j]] = dp[i] + v[j];
          rep(k, 105){
            select[i+w[j]][k] = select[i][k];
          }
          select[i+w[j]][j] = 1;
        }
      }
    }
  }
  // rep(i, W+1) cout << dp[i] << " ";
  // cout << endl;
  // rep(i, W+1){
  //   rep(j, N){
  //     cout << select[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return dp[W];
}

signed main() {
  int N, W;
  cin >> N >> W;
  vector<int> v;
  vector<int> w;
  rep(i, N){
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
    cin >> tmp;
    w.push_back(tmp);
  }
  rep(i, 11005) dp[i] = -1;
  dp[0] = 0; // initialize
  rep(i, 11005) rep(j, 105) select[i][j] = 0;

  cout << knapsack(v, w, N, W) << endl;

  return 0;
}
