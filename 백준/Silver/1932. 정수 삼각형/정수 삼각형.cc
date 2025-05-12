#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];

int main() {
	cin >> N;
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			cin >> arr[i][j];


			int left = 0, right = 0;
			if (i == 0) {
				dp[i][j] = arr[i][j];
				continue;
			}
			if (j > 0) left = dp[i - 1][j - 1];
			right = dp[i - 1][j];

			dp[i][j] = arr[i][j] + max(left, right);
		}
	}

	int result = 0;
	for (int i = 0;i < N;i++) {
		result = max(result, dp[N - 1][i]);
	}
	cout << result;

	return 0;
}