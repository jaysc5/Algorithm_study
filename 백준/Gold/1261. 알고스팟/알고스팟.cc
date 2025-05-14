#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Edge
{
	int x, y, cost;
	
	bool operator<(Edge right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;
int map[100][100];
int dp[100][100];

//int dist[100][100];

//void dijkstra() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			dist[i][j] = 0;
//		}
//	}
//
//	priority_queue<Edge> pq;
//	pq.push({ 0,0,0 });
//
//	while (!pq.empty()) {
//		Edge now = pq.top();
//		pq.pop();
//
//		if (dist[now.x][now.y] < now.cost) continue;
//
//		for (int i = 0; i < 4; i++) {
//			int nx = now.x + dx[i];
//			int ny = now.y + dy[i];
//
//			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//
//			int ncost = dist[now.x][now.y] + (map[nx][ny]-'0');
//
//			if (dist[nx][ny] <= ncost) continue;
//
//			dist[nx][ny] = ncost;
//			pq.push({ nx, ny, ncost });
//		}
//	}
//}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> M >> N;
	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < M; j++) {
			map[i][j] = tmp[j] - '0';
			dp[i][j] = -1;
		}
	}

	priority_queue<Edge> pq;
	pq.push({ 0,0,0 });
	dp[0][0] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dp[now.x][now.y] == -1) continue;

		for (int d = 0; d < 4; d++) {
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			int ncost = dp[now.x][now.y] + map[nx][ny];
			if (dp[nx][ny] != -1 && dp[nx][ny] <= ncost) continue;

			dp[nx][ny] = ncost;
			pq.push({ nx, ny, ncost });
		}
	}

	cout << dp[N - 1][M - 1];

	return 0;
}