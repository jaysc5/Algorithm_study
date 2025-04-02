#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> up;
vector<vector<int>> down;

int checkPerson(int now) {
    int sum = 0;
    queue<int> q;

    q.push(now);
    int visited[501] = { 0, };
    visited[now] = 1;

    int start;
    while (!q.empty()) {
        start = q.front();
        q.pop();

        for (int u : up[start]) {
            if (visited[u] == 1) continue;
            q.push(u);
            sum++;
            visited[u] = 1;
        }
    }

    q.push(now);
    int visited2[501] = { 0, };
    visited2[now] = 1;

    while (!q.empty()) {
        start = q.front();
        q.pop();

        for (int d : down[start]) {
            if (visited2[d] == 1) continue;
            q.push(d);
            sum++;
            visited2[d] = 1;
        }
    }

    return sum;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int i;
    cin >> N;
    cin >> M;

    //up.assign(N + 1, vector<int>(0));
    //down.assign(N + 1, vector<int>(0));

    up = vector<vector<int>>(N + 1);
    down = vector<vector<int>>(N + 1);

    int a, b;
    for (i = 0; i < M; i++) {
        cin >> a >> b;
        down[b].push_back(a);
        up[a].push_back(b);
    }

    int result = 0;
    for (i = 1; i <= N; i++) {
        if (N - 1 == checkPerson(i))
            result++;
    }

    cout << result << "\n";


return 0;
}