#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX 100010

int N, M;
vector<long long> arr(MAX);
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

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    int treeDepth = ceil(log2(N));
    int treeSize = 1 << (treeDepth + 1);
    seg.resize(treeSize);

    for (int i = 1; i <= N; i++) cin >> arr[i];

    build(1, 1, N);

    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << query(1, 1, N, s, e) << "\n";
    }

    return 0;
}
