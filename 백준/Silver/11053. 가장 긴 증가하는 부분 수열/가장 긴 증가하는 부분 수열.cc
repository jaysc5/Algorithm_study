#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	int* dp = new int[n];
	for (int i = 0;i < n;i++) dp[i] = 1;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	sort(dp, dp + n);
	cout << dp[n-1];
	
	return 0;
}