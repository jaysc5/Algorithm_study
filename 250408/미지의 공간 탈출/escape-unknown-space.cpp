#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct event {
    int r, c, d, v;
    bool alive;
    
    event(int R, int C, int D, int V, bool A) : r(R), c(C), d(D), v(V), alive(A) {}
};

struct Coord {
    int r;
    int c;
};

struct wall {
    int r;
    int c;
    int nowwall; // -1 평면, 01234 동서남북위
    int turn;
};

int N, M, F;
int map[20][20]; //0 빈공간 / 1 장애물 / 2 타임머신 / 3 시간 / 4 탈출구 / 5 시간이상지역 / 6 방문
int timeMap[5][10][10]; //동서남북위
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
Coord timeP = { -1,-1 }, exitP;
vector<event> TimeEvent;
queue<wall> q;

void input() {
    cin >> N >> M >> F;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> map[i][j];
            if (map[i][j] == 4) exitP = { i, j };
            if (map[i][j] == 3 && timeP.r == -1 && timeP.c == -1) timeP = { i, j };
        }
    }

    for (int k = 0;k < 5;k++) {
        for (int i = 0;i < M;i++) {
            for (int j = 0;j < M;j++) {
                cin >> timeMap[k][i][j];
                if (timeMap[k][i][j] == 2) q.push({ i, j, k, 0 });
            }
        }
    }

    for (int i = 0;i < F;i++) {
        int ri, ci, di, vi;
        cin >> ri >> ci >> di >> vi;
        TimeEvent.push_back(event(ri, ci, di, vi, true));
        map[ri][ci] = 5;
    }
}

int solution() {
    int answer = -1;

    while (!q.empty()) {
        wall now = q.front();
        q.pop();

        // 시간 이상 현상 구현
        for (int e = 0;e < F;e++) {
            if (now.turn >= TimeEvent[e].v && now.turn % TimeEvent[e].v == 0 && TimeEvent[e].alive == true) {
                int nk = now.turn / TimeEvent[e].v;
                int nr = TimeEvent[e].r + nk * dx[TimeEvent[e].d];
                int nc = TimeEvent[e].c + nk * dy[TimeEvent[e].d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    TimeEvent[e].alive = false;
                    continue;
                }
                if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 4) {
                    TimeEvent[e].alive = false;
                    continue;
                }

                map[nr][nc] = 5;
            }
        }

        // 상하좌우 이동 하기
        if (now.nowwall == -1) { // 평면일때
            if (now.r < 0 || now.r >= N || now.c < 0 || now.c >= N) continue;
            if (map[now.r][now.c] == 1 || map[now.r][now.c] == 3 || map[now.r][now.c] == 5 || map[now.r][now.c] == 6) continue;
            if (map[now.r][now.c] == 4) {
                answer = now.turn;
                break;
            }

            map[now.r][now.c] = 6;
            q.push({ now.r, now.c + 1, now.nowwall, now.turn + 1 });
            q.push({ now.r, now.c - 1, now.nowwall, now.turn + 1 });
            q.push({ now.r + 1, now.c, now.nowwall, now.turn + 1 });
            q.push({ now.r - 1, now.c, now.nowwall, now.turn + 1 });
        }
        else { // 시간의 벽일때
            int newW = now.nowwall, newR = now.r, newC = now.c;
            if (now.r < 0) {
                if (now.nowwall == 4) {
                    newW = 3;
                    newR = 0;
                    newC = (M - 1) - now.c;
                }
                else {
                    newW = 4;
                    if (now.nowwall == 0) { newR = (M - 1) - now.c; newC = (M - 1); }
                    if (now.nowwall == 1) { newR = now.c; newC = 0; }
                    if (now.nowwall == 2) { newR = (M - 1); newC = now.c; }
                    if (now.nowwall == 3) { newR = 0; newC = (M - 1) - now.c; }
                }
            }
            else if (now.r >= M) {
                if (now.nowwall == 4) {
                    newW = 2;
                    newR = 0;
                    newC = now.c;
                }
                else {
                    newW = -1;
                    if (now.nowwall == 0) { newR = timeP.r + (M - 1) - now.c; newC = timeP.c + M; }
                    if (now.nowwall == 1) { newR = timeP.r + now.c; newC = timeP.c - 1; }
                    if (now.nowwall == 2) { newR = timeP.r + M; newC = timeP.c + now.c; }
                    if (now.nowwall == 3) { newR = timeP.r - 1; newC = timeP.c + (M - 1) - now.c; }
                }
            }
            else if (now.c < 0) {
                if (now.nowwall == 4) {
                    newW = 1;
                    newR = 0;
                    newC = now.r;
                }
                else {
                    newR = now.r;
                    newC = (M - 1);
                    if (now.nowwall == 0) newW = 2;
                    if (now.nowwall == 1) newW = 3;
                    if (now.nowwall == 2) newW = 1;
                    if (now.nowwall == 3) newW = 0;
                }
            }
            else if (now.c >= M) {
                if (now.nowwall == 4) {
                    newW = 0;
                    newR = 0;
                    newC = (M - 1) - now.r;
                }
                else {
                    newR = now.r;
                    newC = 0;
                    if (now.nowwall == 0) newW = 3;
                    if (now.nowwall == 1) newW = 2;
                    if (now.nowwall == 2) newW = 0;
                    if (now.nowwall == 3) newW = 1;
                }
            }

            if (newW == -1) {
                if (map[newR][newC] == 1 || map[newR][newC] == 3 || map[newR][newC] == 5 || map[newR][newC] == 6) continue;
                if (map[newR][newC] == 4) {
                    answer = now.turn;
                    break;
                }

                map[newR][newC] = 6;
                q.push({ newR, newC + 1, -1, now.turn + 1 });
                q.push({ newR, newC - 1, -1, now.turn + 1 });
                q.push({ newR + 1, newC, -1, now.turn + 1 });
                q.push({ newR - 1, newC, -1, now.turn + 1 });

            }
            else {
                if (timeMap[newW][newR][newC] == 1 || timeMap[newW][newR][newC] == 6) continue;
                timeMap[newW][newR][newC] = 6;

                q.push({ newR, newC + 1, newW, now.turn + 1 });
                q.push({ newR, newC - 1, newW, now.turn + 1 });
                q.push({ newR + 1, newC, newW, now.turn + 1 });
                q.push({ newR - 1, newC, newW, now.turn + 1 });
            }
        }
    }

    return answer;
}

int main() {
    
    input();

    int result = solution();
    cout << result;

    return 0;
}
