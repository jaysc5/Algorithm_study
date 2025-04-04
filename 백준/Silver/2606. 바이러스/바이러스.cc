#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
vector<vector<int>> arr;
int used[101] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	arr.assign(N + 1, vector<int>(0));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	used[1] = 1;

	int cnt = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			if (used[arr[now][i]]) continue;
			q.push(arr[now][i]);
			used[arr[now][i]] = 1;
			cnt++;
		}
	}

	/*if (cnt == 0) cout << -1;
	else */
	cout << cnt;

	return 0;
}
