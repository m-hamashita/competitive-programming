#include <iostream>
#include <vector>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

long long pow_mod(long long x, long long y, long long MOD) {
  long long ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}

signed main() {
  int N, M;
  int k, tmp;
  // 入力部分
  cin >> N >> M;
  vector<vector<int>> v(M, vector<int>(M));
  rep(i, M){
    cin >> k;
    rep(j, k){
      cin >> tmp;
      v[i].push_back(tmp);
    }
  }
  int p[M];
  rep(i, M){
    cin >> p[i];
  }

  // 処理部分
  int result = 0;
  bool all_on;
  // bit全探索 N <= 10
  for(int i = 0;i < (1<<N);i++){
    all_on = true;
    for(int j=0;j<v.size();j++){
      int switch_count = 0;
      for(auto sw: v[j]){
        if(i&(1<<(sw-1)))switch_count++;
      }
      if (switch_count%2 != p[j]){
        all_on = false;
        break;
      }
    }
    if (all_on){
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
