#include<iostream>
#include<queue>
#include<vector>
#include<limits>

using namespace std;

struct Edge {
	int num;
	int cost;
	bool operator<(Edge right)const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

int N, M;
vector<Edge> alis[801];
int dist[801];
int INF = 1e9 / 3;

int func(int start, int end) {
	priority_queue<Edge> pq;
	pq.push({ start, 0 });

	for (int i = 0; i <= N; i++) dist[i] = INF;
	dist[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < alis[now.num].size(); i++) {
			Edge next = alis[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (nextcost >= dist[next.num]) continue;

			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}

	return dist[end];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		alis[u].push_back({ v, w });
		alis[v].push_back({ u, w });
	}

	int tmp1, tmp2;
	cin >> tmp1 >> tmp2;

	long long result = 0;
	if (tmp1 == 1 && tmp2 == N) {
		result = func(1, N);
	}
	else {
		long long result1 = func(1, tmp1) + func(tmp1, tmp2) + func(tmp2, N);
		long long result2 = func(1, tmp2) + func(tmp2, tmp1) + func(tmp1, N);
		result = min(result1, result2);
	}

	if (result >= INF || result < 0) cout << -1;
	else cout << result;

	return 0;
}