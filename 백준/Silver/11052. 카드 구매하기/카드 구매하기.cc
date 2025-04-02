#include <iostream>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

int N;
int dp[1001];

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> dp[i];

        for (int j = 0;j < i;j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j - 1]);
        }
    }
    cout << dp[N - 1];

    return 0;;
}
