#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int N;
double dp[305][305][305];

double recursion(int i, int j, int k) {
  if (dp[i][j][k] >= 0)
    return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0)
    return 0.0;
  double result = 0.0;
  if (i > 0)
    result += i * recursion(i - 1, j, k);
  if (j > 0)
    result += j * recursion(i + 1, j - 1, k);
  if (k > 0)
    result += k * recursion(i, j + 1, k - 1);
  result += N;
  result *= 1.0 / (i + j + k);

  dp[i][j][k] = result;
  return result;
}

signed main() {
  cin >> N;
  int a[3];
  a[0] = a[1] = a[2] = 0;
  rep(i, N) {
    int tmp;
    cin >> tmp;
    a[tmp - 1]++;
  }
  rep(i, 305) rep(j, 305) rep(k, 305) dp[i][j][k] = -1;
  cout << fixed << setprecision(10) << recursion(a[0], a[1], a[2]) << endl;

  return 0;
}
