#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	int* arr = new int[N];
	int* dp = new int[N];
	for (int i = 0;i < N;i++) cin >> arr[i];

	int ans = numeric_limits<int>::min();
	for (int i = 0;i < N;++i) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}