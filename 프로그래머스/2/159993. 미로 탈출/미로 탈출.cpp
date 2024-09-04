#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Point {
    int x, y, cnt;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

bool isWithinRange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

Point findStartPoint(char start, vector<string> &maps) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maps[i][j] == start) {
                return {i, j, 0};
            }
        }
    }
    return {-1, -1, -1};
}

int bfs(char start, char end, vector<string> &maps) {
    bool visited[101][101] = {false};
    queue<Point> q;
    q.push(findStartPoint(start, maps));
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        if (maps[cur.x][cur.y] == end) {
            return cur.cnt;
        }
        
        for (int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (isWithinRange(nx, ny) && !visited[nx][ny] && maps[nx][ny] != 'X') {
                q.push({nx, ny, cur.cnt + 1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    int distanceStoL = bfs('S', 'L', maps);
    if (distanceStoL == -1) return -1;
    
    int distanceLtoE = bfs('L', 'E', maps);
    if (distanceLtoE == -1) return -1;
    else return distanceStoL + distanceLtoE;
}