#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int dp[100001];

int main() {
	cin >> N;

	dp[0] = dp[1] = dp[3] = 999999;
	dp[2] = dp[5] = 1;
	dp[4] = 2;

	for(int i=6;i<=N;i++){
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}

	if (dp[N] == 999999) cout << -1;
	else cout << dp[N];

	return 0;
}