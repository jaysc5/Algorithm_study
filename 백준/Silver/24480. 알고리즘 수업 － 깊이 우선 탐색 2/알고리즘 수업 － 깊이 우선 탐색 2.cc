#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

void dfs(int r) {
	if (visited[r] == 1) {
		return;
	}

	visited[r] = 1;
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}
int main() {
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].rbegin(), graph[i].rend());
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}

}
