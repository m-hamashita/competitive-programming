#include <iostream>

using namespace std;

signed main() {
    long long N, K;
    cin >> N >> K;
    long long s[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    long long right = 0;
    long long total = 1;
    long long result = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && total * s[right] <= K) {
            total *= s[right];
            right++;
        }
        result = max(result, right - left);
        if (left == right)
            right++;
        else
            total /= s[left];
    }
    cout << result << endl;

    return 0;
}
