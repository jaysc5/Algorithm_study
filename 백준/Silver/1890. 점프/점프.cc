#include <iostream>
#include<algorithm>

using namespace std;

int N;
int arr[105][105];
long long dp[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || arr[i][j] == 0) continue;

			int k = arr[i][j];

			if ((i + k) < N) dp[i + k][j] += dp[i][j];
			if ((j + k) < N) dp[i][j + k] += dp[i][j];

		}
	}

	cout << dp[N - 1][N - 1];

	return 0;
}