#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N, M;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (unsigned int i = 0; i < N; i++) {
        for (unsigned int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    cin >> M;
    for (unsigned int i = 0; i < v.size() - 1; i++) {
    }
}
