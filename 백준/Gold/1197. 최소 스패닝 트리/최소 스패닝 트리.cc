#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
	int A, B, cost;
};

int V, E;
vector<Edge> edges;
int parent[10001];

bool cmp(Edge a, Edge b) {
	return a.cost < b.cost;
}

int Find(int now) {
	if (now == parent[now]) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int roota = Find(a);
	int rootb = Find(b);

	if (roota == rootb) return;
	parent[rootb] = roota;
}

int main() {
	cin >> V >> E;
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}
	sort(edges.begin(), edges.end(), cmp);

	for (int i = 1;i <= V;i++) {
		parent[i] = i;
	}

	long long sum = 0;
	for (int i = 0;i < E; i++) {
		Edge now = edges[i];

		if (Find(now.A) == Find(now.B)) continue;
		Union(now.A, now.B);
		sum += now.cost;
	}

	cout << sum;
}