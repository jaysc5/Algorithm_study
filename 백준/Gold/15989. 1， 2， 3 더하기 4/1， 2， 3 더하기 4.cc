#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

int dp[10001] = { 0, };

int main() {
	int T;
	cin >> T;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2;i < 10001;i++)
		dp[i] = dp[i - 2] + 1;
	for (int i = 3;i < 10001;i++)
		dp[i] += dp[i - 3];


	for (int tc = 0;tc < T;tc++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
