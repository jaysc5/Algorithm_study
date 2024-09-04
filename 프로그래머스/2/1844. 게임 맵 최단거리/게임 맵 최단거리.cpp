#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int check[MAX_SIZE][MAX_SIZE];

struct Point {
    int x, y;
    
    Point(int x, int y) : x(x), y(y) {}
    
    bool isValid(int n, int m) { return 0 <= x && x < n && 0 <= y && y < m; }
    
    Point move(int i) const { return Point(x+dx[i], y+dy[i]); }
    
    bool canMoveTo(const vector<vector<int>> &maps) const { return maps[x][y] == 1 && check[x][y] == 0; }
};

queue<Point> q;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int end_x = n-1, end_y = m-1;

    q.push({0, 0});
    check[0][0] = 1;
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            Point next = cur.move(i);
            if (next.isValid(n, m) && next.canMoveTo(maps)) {
                check[next.x][next.y] = check[cur.x][cur.y] + 1;
                q.push({next.x, next.y});
            }
        }
    }
    
    if (check[end_x][end_y] == 0) return -1;
    return check[end_x][end_y];
}