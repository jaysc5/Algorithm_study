#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int** dp = new int*[n + 1];
	for (int i = 0;i < n + 1;i++) dp[i] = new int[10];

	dp[1][0] = 0;
	for (int i = 1;i <= 9;i++) {
		dp[1][i] = 1;
	}

	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}

	long long result = 0;
	for (int i = 0;i <= 9;i++) {
		result += dp[n][i];
	}
	cout << result % 1000000000;

	return 0;
}