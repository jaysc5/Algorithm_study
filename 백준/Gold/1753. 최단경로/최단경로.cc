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
vector<Edge> alis[20001];
int dist[20001];
int INF = numeric_limits<int>::max();

void func(int start) {
	priority_queue<Edge> pq;
	pq.push({ start, 0 });

	for (int i = 0;i <= N;i++) dist[i] = INF;
	dist[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0;i < alis[now.num].size();i++) {
			Edge next = alis[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (nextcost >= dist[next.num]) continue;

			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {
	cin >> N >> M;

	int s;
	cin >> s;

	for (int i = 0;i < M;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		alis[u].push_back({ v, w });
	}

	func(s);

	for (int i = 1;i <= N;i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}