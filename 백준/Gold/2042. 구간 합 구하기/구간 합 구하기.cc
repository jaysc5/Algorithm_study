#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
#include <math.h>

#define MAX 1000000

using namespace std;

const int INF = numeric_limits<int>::max();
int N, M, K;
vector<long long> arr;
vector<long long> seg;

long long build(int node, int start, int end) {
	if (start == end) return seg[node] = arr[start];

	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	return seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long val) {
	if (idx<start || idx > end) return;
	seg[node] += val;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, val);
	update(2 * node + 1, mid + 1, end, idx, val);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> K;

	int treeDepth = ceil(log2(N));
	int treeSize = 1 << (treeDepth + 1);
	seg.resize(treeSize);
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++) cin >> arr[i];

	build(1, 1, N);

	int cnt = M + K;
	while (cnt--) {
		int t;
		long long s, e;
		cin >> t >> s >> e;
		if (t == 1) {
			long long tmp = e - arr[s];
			arr[s] = e;
			update(1, 1, N, s, tmp);
		}
		else if (t == 2) {
			cout << query(1, 1, N, s, e) << "\n";
		}
	}


	return 0;
}
