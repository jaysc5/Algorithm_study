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

int N, M, X;
vector<Edge> alis1[1001];
int dist1[1001];
vector<Edge> alis2[1001];
int dist2[1001];
int INF = numeric_limits<int>::max();
int result = numeric_limits<int>::min();

void func1(int start) {
	priority_queue<Edge> pq;
	pq.push({ start, 0 });

	for (int i = 0; i <= N; i++) dist1[i] = INF;
	dist1[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist1[now.num] < now.cost) continue;

		for (int i = 0; i < alis1[now.num].size(); i++) {
			Edge next = alis1[now.num][i];
			int nextcost = dist1[now.num] + next.cost;

			if (nextcost >= dist1[next.num]) continue;

			dist1[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

void func2(int start) {
	priority_queue<Edge> pq;
	pq.push({ start, 0 });

	for (int i = 0; i <= N; i++) dist2[i] = INF;
	dist2[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist2[now.num] < now.cost) continue;

		for (int i = 0; i < alis2[now.num].size(); i++) {
			Edge next = alis2[now.num][i];
			int nextcost = dist2[now.num] + next.cost;

			if (nextcost >= dist2[next.num]) continue;

			dist2[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		alis1[u].push_back({ v, w });
		alis2[v].push_back({ u, w });
	}


	for (int i = 1; i <= N; i++) {
		func1(i);
		func2(i);
		int tmp = dist1[X] + dist2[X];
		result = max(result, tmp);
	}

	cout << result;

	return 0;
}