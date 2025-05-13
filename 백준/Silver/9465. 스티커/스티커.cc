#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[2][100001];
int dp[2][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		cin >> N;

		for (int i = 0;i < 2;i++) {
			for (int j = 1;j <= N;j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2;i <= N;i++) {
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + arr[1][i];
		}

		cout << max(dp[0][N], dp[1][N]) << "\n";
	}
	return 0;
}

