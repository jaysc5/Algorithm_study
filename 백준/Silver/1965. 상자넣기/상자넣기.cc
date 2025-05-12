#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int N;
int arr[1001], dp[1001];

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	int result = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}

		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}