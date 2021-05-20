#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;


signed main() {
  int N;
  cin >> N;
  int M;
  string S1, S2, S3;
  rep(i, N){
    cin >> M;
    cin >> S1 >> S2 >> S3;
    if (M == 1){
      cout << "010" << endl;
      continue;
    }else if (M==2){
      cout << "00110" <<endl;
      continue;
    }
    cout << "1";
    rep(i, M){
      cout << "0";
    }
    rep(i, M){
      cout << "1";
    }
    cout << endl;

  }

  return 0;
}
