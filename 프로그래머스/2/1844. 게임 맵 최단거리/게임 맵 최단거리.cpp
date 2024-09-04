#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
int check[MAX_SIZE][MAX_SIZE];

bool isWithinRange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    n = maps.size(), m = maps[0].size();
    int end_x = n-1, end_y = m-1;

    q.push({0, 0});
    check[0][0] = 1;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.first == end_x && cur.second == end_y) {
            return check[end_x][end_y];
        }

        for (int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if (isWithinRange(nx, ny) && maps[nx][ny] == 1 && check[nx][ny] == 0) {
                check[nx][ny] = check[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    if (check[end_x][end_y] == 0) return -1;
    return check[end_x][end_y];
}