#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* dp = new int[n + 1];
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3;i <= n;i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
	}
	cout << dp[n];

	return 0;
}