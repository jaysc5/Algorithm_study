#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;

struct Edge {
	int num;
	int cost;
	bool operator<(Edge right)const {
		//weigt가 가장 저렴한 간선 우선적으로 뽑는다.
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;

		return false;
	}
};

vector<Edge>* alis;
int* dist;
void dijkstra(int start) {
	priority_queue<Edge>pq;
	for (int i = 0; i <= N; i++) {
		dist[i] = 21e8;
	}

	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < alis[now.num].size(); i++) {
			Edge next = alis[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (nextcost >= dist[next.num])continue;

			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {

	cin >> N >> M;

	alis = new vector<Edge>[N + 1];
	dist = new int[N + 1];

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		alis[from].push_back({ to,cost });
		alis[to].push_back({ from,cost });
	}

	dijkstra(1);
	cout << dist[N];

	delete[] alis;
	delete[] dist;

	return 0;
}