#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int N;
int** arr;
long long** dp;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	arr = new int* [N];
	dp = new long long* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		dp[i] = new long long[N] {0};
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || arr[i][j] == 0) continue;

			int jump = arr[i][j];

			if (i + jump < N) dp[i + jump][j] += dp[i][j];

			if (j + jump < N) dp[i][j + jump] += dp[i][j];

		}
	}
	

	cout << dp[N - 1][N - 1];

	return 0;
}
