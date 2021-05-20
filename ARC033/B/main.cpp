#include <iostream>
#include <map>

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
  map<int, int> mp;
  int N1, N2;
  cin >> N1 >> N2;
  int A, B;
  rep(i, N1){
    cin >> A;
    mp[A]++;
  }
  rep(i, N2){
    cin >> B;
    mp[B]++;
  }
  int both = 0;
  int either = 0;
  for (auto iter = mp.begin(); iter != mp.end(); iter++){
    if (iter->second == 2){
      both++;
    }
    either++;
  }

  cout << double(both)/either << endl;
  return 0;
}
