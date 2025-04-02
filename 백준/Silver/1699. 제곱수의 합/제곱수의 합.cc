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

	int* dp = new int[N];
	for(int i=0;i<=N;i++) dp[i] = i;

	for (int i = 1;i <= N;++i) {
		for (int j = 1;j * j <= i;j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}

	}
	cout << dp[N];

	return 0;
}