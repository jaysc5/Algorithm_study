#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int dp[1000001];
vector<int> path;

int main() {
	cin >> N;

	dp[1] = 0;
	dp[2] = dp[3] = 1;
	path.push_back(1);

	for (int i = 4;i <= N;i++) {
		int num2 = 99999, num3 = 99999;
		if (i % 3 == 0) num3 = dp[i / 3];
		if (i % 2 == 0) num2 = dp[i / 2];

		dp[i] = min(dp[i - 1] + 1, min(num2 + 1, num3 + 1));
	}

	cout << dp[N] << "\n";

	while (true) {
		cout << N << " ";

		if (N <= 1) break;

		if (dp[N] == dp[N - 1] + 1) N -= 1;
		else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1) N /= 2;
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1) N /= 3;
	}

	return 0;
}