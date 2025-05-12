#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int dp[100001];

int main() {
	cin >> N;

	memset(dp, 999999, (N+1) * sizeof(int));
	dp[0] = dp[1] = dp[3] = -1;
	dp[2] = dp[5] = 1;
	dp[4] = 2;

	for(int i=6;i<=N;i++){
		int num2 = 999999, num5 = 999999;
		if (dp[i - 2] != -1) num2 = dp[i - 2];
		if (dp[i - 5] != -1) num5 = dp[i - 5];

		dp[i] = min(dp[i], min(num2 + 1, num5 + 1));
	}

	cout << dp[N];

	return 0;
}