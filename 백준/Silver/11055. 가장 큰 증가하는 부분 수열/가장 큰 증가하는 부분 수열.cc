#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int result;

int main() {
	cin >> N;
	
	dp[0] = 0;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		dp[i] = arr[i];

		for (int j = 1;j <= i;j++) {
			if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}

		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}