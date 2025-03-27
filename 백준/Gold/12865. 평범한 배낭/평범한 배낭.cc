#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

int dp[101][100001] = { 0, };

struct node
{
	int w;
	int v;
};

int main() {
	int N, K;
	cin >> N >> K;

	vector<node> knapsack;
	for (int i = 0;i < N;i++) {
		int w, v;
		cin >> w >> v;
		knapsack.push_back({ w, v });
	}

	for (int i = 1;i <= N;i++) {
		int curW = knapsack[i - 1].w;
		int curV = knapsack[i - 1].v;
		for (int j = 1;j <= K;j++) {
			if (curW <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curW] + curV);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}
