#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge {
	int A;
	int B;
	int cost;
};

bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}

int N;
vector<Edge> edges;
int parent[301];

int Find(int now) {

	if (now == parent[now])return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {

	int rootA = Find(A);
	int rootB = Find(B);

	if (rootA == rootB)return;
	parent[rootB] = rootA;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		edges.push_back({ 0,i,cost });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;

			if (i <= j) continue;
			edges.push_back({ i, j, cost });
		}
	}

	sort(edges.begin(), edges.end(), cmp);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	
	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		Edge now = edges[i];

		if (Find(now.A) == Find(now.B)) continue;
		Union(now.A, now.B);
		sum += now.cost;
	}

	cout << sum << "\n";

}