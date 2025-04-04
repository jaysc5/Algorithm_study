#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1'000'001;
vector<int> adj[MAX];
int dp[MAX][2];  // [0] = 얼리 아답터 아님, [1] = 얼리 아답터
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;  // node가 얼리 아답터 아님
    dp[node][1] = 1;  // node가 얼리 아답터임

    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += dp[child][1];  // 내가 얼리 아답터 아니면, 자식은 무조건 얼리 아답터
            dp[node][1] += min(dp[child][0], dp[child][1]);  // 내가 얼리 아답터면, 자식은 아무거나
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
