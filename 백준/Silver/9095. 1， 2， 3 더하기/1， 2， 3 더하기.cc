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
	
	int T;
	cin >> T;

	int* dp = new int[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4;i <= 11;++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int tc = 0; tc < T;tc++) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}