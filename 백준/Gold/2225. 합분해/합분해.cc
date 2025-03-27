#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

int dp[201][201] = { 0, };

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0;i <= K;i++) {
		dp[1][i] = i;
	}

	for (int i = 2;i <= N;i++) {
		for (int j = 1;j <= K;j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K];

	return 0;
}
