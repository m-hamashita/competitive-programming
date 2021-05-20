#include <iostream>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
  int N;
  cin >> N;
  int A[N];
  rep(i, N){
    cin >> A[i];
  }
  bitset<30> s=0;
  rep(i, N){
    bitset<30> tmp(A[i]);
    s = s ^ tmp;
  }
  rep(i, N){
    bitset<30> tmp(A[i]);
    cout << (s ^ tmp).to_ullong();
    cout << " ";
  }
  cout << endl;

  return 0;
}
