#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Coord {
    int z, x, y;
};

int N, M, K;
int map[1005][1005];
int visited[11][1005][1005];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(Coord s) {
    queue<Coord> q;
    q.push(s);

    visited[s.z][s.x][s.y] = 1;

    while (!q.empty()) {
        Coord now = q.front();
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nz = now.z;
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (0 >= nx || nx > N || 0 >= ny || ny > M) continue;

            if (visited[nz][nx][ny] > 0) continue;
            
            if (map[nx][ny] == 1 && nz < K) {
                if (visited[nz + 1][nx][ny] == -1) {
                visited[nz + 1][nx][ny] = visited[now.z][now.x][now.y] + 1;
                q.push({ nz + 1, nx, ny });
                }
            }
            else if (map[nx][ny] == 0) {
                visited[nz][nx][ny] = visited[now.z][now.x][now.y] + 1;
                q.push({ nz, nx, ny });           
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 1;i <= N;i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1;j <= M;j++) {
            map[i][j] = int(tmp[j - 1] - '0');
        }
    }

    for (int k = 0;k <= K;k++) {
        for (int i = 1;i <= N;i++) {
            for (int j = 1;j <= M;j++) {
                visited[k][i][j] = -1;
            }
        }
    }

    bfs({ 0,1,1 });

    int result = 21e8;
    for (int k = 0;k <= K;k++) {
        if (visited[k][N][M] != -1) {
            result = min(result, visited[k][N][M]);
        }
    }
    
    if (result == 21e8) cout << -1;
    else cout << result;

    return 0;
}
