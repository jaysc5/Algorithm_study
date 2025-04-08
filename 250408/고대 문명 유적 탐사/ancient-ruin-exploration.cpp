#include <iostream>
#include <queue>

using namespace std;

#define N_large 5
#define N_small 3

class Board {
public:
    int map[N_large][N_large];

private:
    bool InRange(int y, int x) {
        return 0 <= y && y < N_large && 0 <= x && x < N_large;
    }

public:
    Board() {
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                map[i][j] = 0;
            }
        }
    }

    Board* Rotate(const int sy, const int sx, const int cnt) {
        Board* result = new Board();
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                result->map[i][j] = map[i][j];
            }
        }
        for (int k = 0; k < cnt; k++) {
            int tmp = result->map[sy + 0][sx + 2];
            result->map[sy + 0][sx + 2] = result->map[sy + 0][sx + 0];
            result->map[sy + 0][sx + 0] = result->map[sy + 2][sx + 0];
            result->map[sy + 2][sx + 0] = result->map[sy + 2][sx + 2];
            result->map[sy + 2][sx + 2] = tmp;
            tmp = result->map[sy + 1][sx + 2];
            result->map[sy + 1][sx + 2] = result->map[sy + 0][sx + 1];
            result->map[sy + 0][sx + 1] = result->map[sy + 1][sx + 0];
            result->map[sy + 1][sx + 0] = result->map[sy + 2][sx + 1];
            result->map[sy + 2][sx + 1] = tmp;
        }
        return result;
    }

    int CalScore() {
        int score = 0;
        bool visited[N_large][N_large];
        int dy[4] = { 0,1,0,-1 };
        int dx[4] = { 1,0,-1,0 };

        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                if (!visited[i][j]) {
                    queue<pair<int, int>> q, trace;
                    q.push({ i, j });
                    trace.push({ i, j });
                    visited[i][j] = true;

                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];
                            if (InRange(ny, nx) && map[ny][nx] == map[cur.first][cur.second] && (!visited[ny][nx])) {
                                q.push({ ny, nx });
                                trace.push({ ny, nx });
                                visited[ny][nx] = true;
                            }
                        }
                    }

                    if (trace.size() >= 3) {
                        score += trace.size();
                        while (!trace.empty()) {
                            pair<int, int> t = trace.front();
                            trace.pop();
                            map[t.first][t.second] = 0;
                        }
                    }
                }
            }
        }
        return score;
    }

    void floodfill(queue<int>* que) {
        for (int row = 0; row < N_large; row++) {
            for (int col = N_large - 1; col >= 0; col--) {
                if (map[col][row] == 0) {
                    map[col][row] = que->front();
                    que->pop();
                }
            }
        }
    }

};

int main() {
    int K, M;
    queue<int> q;
    Board* board = new Board();

    cin >> K >> M;

    for (int i = 0; i < N_large; i++) {
        for (int j = 0; j < N_large; j++) {
            cin >> board->map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    while (K--) {
        int maxScore = 0;
        Board* maxScoreBoard = NULL;

        for (int cnt = 1; cnt <= 3; cnt++) {
            for (int sx = 0; sx <= N_large - N_small; sx++) {
                for (int sy = 0; sy <= N_large - N_small; sy++) {
                    Board* rotated = board->Rotate(sy, sx, cnt);
                    int score = rotated->CalScore();
                    if (maxScore < score) {
                        maxScore = score;
                        maxScoreBoard = rotated;
                    }
                }
            }
        }

        if (maxScoreBoard == NULL) break;

        board = maxScoreBoard;
        while (true) {
            board->floodfill(&q);
            int newScore = 0;
            newScore = board->CalScore();
            if (newScore == 0) break;
            maxScore += newScore;
        }

        cout << maxScore << " ";
    }

    return 0;
}
