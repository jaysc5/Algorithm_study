#include <iostream>
#include <queue>

using namespace std;

struct Coord {
    int x, y;
};

struct Info {
    Coord p;
    bool isDead;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;
Coord startP, endP;
Info warriorPositions[50];
int map[50][50];
int visited[50][50];
bool sightMap[50][50];
int warriorCountGrid[50][50];

int warriorDist, stoneWarrior, attackWarrior;

bool isRangeOver(int nx, int ny) {
    return nx < 0 || nx >= N || ny < 0 || ny >= N;
}

void bfs(Coord start) {
    queue<Coord> q;
    q.push(start);
    visited[start.x][start.y] = 1;

    while (!q.empty()) {
        Coord now = q.front();
        q.pop();

        if (now.x == startP.x && now.y == startP.y) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (isRangeOver(nx, ny)) continue;
            if (map[nx][ny] != 0) continue;
            if (visited[nx][ny] > 0) continue;

            visited[nx][ny] = visited[now.x][now.y] + 1;
            q.push({ nx, ny });
        }
    }
}

Coord movePlayer(Coord now) {
    Coord result{};

    // 메두사 이동
    for (int i = 0; i < 4; i++) {
        int nx = now.x + dx[i];
        int ny = now.y + dy[i];

        if (isRangeOver(nx, ny)) continue;
        if (map[nx][ny] != 0) continue;
        if (visited[nx][ny] == 0) continue;

        if (visited[nx][ny] < visited[now.x][now.y]) {
            result.x = nx;
            result.y = ny;
            break;
        }
    }
    return result;
}

void killWarrior(Coord now) {
    // 전사 있으면 죽기
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].isDead) continue;

        if (now.x == warriorPositions[i].p.x && now.y == warriorPositions[i].p.y) {
            warriorPositions[i].isDead = true;
        }
    }
}

void updateWarriorCountGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            warriorCountGrid[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].isDead) continue;

        int x = warriorPositions[i].p.x;
        int y = warriorPositions[i].p.y;
        warriorCountGrid[x][y] += 1;
    }
}

int sightUp(Coord now, bool isTest);
int sightDown(Coord now, bool isTest);
int sightLeft(Coord now, bool isTest);
int sightRight(Coord now, bool isTest);

void initSightMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sightMap[i][j] = 0;
        }
    }
}

void printSightMap(Coord now) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (now.x == i && now.y == j) cout << "x";
            else cout << sightMap[i][j];
        }
        cout << "\n";
    }
}

void chooseBestSight(Coord now) {
    int maxCover = -1, bestDir = -1;

    typedef int (*SightFunc)(Coord, bool);
    SightFunc sightFunction[4] = { sightUp, sightDown, sightLeft, sightRight };

    // 상하좌우 가보면서 max로 전사를 돌로 만드는 시야 찾기
    for (int d = 0; d < 4; d++) {
        initSightMap();

        int coverNow = sightFunction[d](now, true);
        if (maxCover < coverNow) {
            maxCover = coverNow;
            bestDir = d;
        }
    }

    // 실제 시야 설정
    initSightMap();
    sightFunction[bestDir](now, false);

    // 돌로 만든 전사 수 업데이트
    stoneWarrior = maxCover;

    return;
}

int calculateManhattanDistance(Coord a, Coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void moveWarriors(Coord now) {
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].isDead) continue;

        int wx = warriorPositions[i].p.x;
        int wy = warriorPositions[i].p.y;

        // 시야 내에 있으면 이동 안함
        if (sightMap[wx][wy]) continue;

        // 현재 거리
        int curDist = calculateManhattanDistance(now, { wx, wy });
        bool isMoved = false;

        // 거리 줄이는 방향 (상하좌우)
        for (int i = 0; i < 4; i++) {
            int nx = wx + dx[i];
            int ny = wy + dy[i];

            // 격자 밖, 시야 안
            if (isRangeOver(nx, ny)) continue;
            if (sightMap[nx][ny]) continue;

            int newDist = calculateManhattanDistance(now, { nx, ny });
            if (newDist < curDist) {
                wx = nx;
                wy = ny;
                isMoved = true;
                warriorDist++;
                break;
            }
        }

        // 거리 줄이는 방향 (좌우상하)
        if (isMoved) {
            int curDist = calculateManhattanDistance(now, { wx, wy });
            for (int i = 0; i < 4; i++) {
                int nx = wx + dx[(i + 2) % 4];
                int ny = wy + dy[(i + 2) % 4];

                // 격자 밖, 시야 안
                if (isRangeOver(nx, ny)) continue;
                if (sightMap[nx][ny]) continue;

                int newDist = calculateManhattanDistance(now, { nx, ny });
                if (newDist < curDist) {
                    wx = nx;
                    wy = ny;
                    warriorDist++;
                    break;
                }
            }
        }

        // 전사 위치 업데이트
        warriorPositions[i].p.x = wx;
        warriorPositions[i].p.y = wy;
    }
    return;
}

void attack(Coord now) {    
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].isDead) continue;

        int wx = warriorPositions[i].p.x;
        int wy = warriorPositions[i].p.y;

        if (wx == now.x && wy == now.y) {
            attackWarrior++;
            warriorPositions[i].isDead = true;
        }
    }
    return;
}
int main() {
    cin >> N >> M;
    
    cin >> startP.x >> startP.y >> endP.x >> endP.y;

    for (int i = 0; i < M; i++) {
        cin >> warriorPositions[i].p.x >> warriorPositions[i].p.y;
        warriorPositions[i].isDead = false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    bfs(endP);
    if (visited[startP.x][startP.y] == 0) {
        cout << -1;
        return 0;
    }

    Coord currentP = startP;
    while (true) {
        warriorDist = 0, stoneWarrior = 0, attackWarrior = 0;

        // 메두사의 이동
        currentP = movePlayer(currentP);

        // 끝에 도달하면 중단
        if (currentP.x == endP.x && currentP.y == endP.y) {
            cout << 0;
            break;
        }

        // 메두사 이동 후 전사 죽이기
        killWarrior(currentP);

        // 메두사의 시선
        updateWarriorCountGrid(); // 전사 맵
        chooseBestSight(currentP); // 시선 선택
        //printSightMap(currentP);

        // 전사들의 이동
        moveWarriors(currentP);

        // 전사들의 공격
        attack(currentP);

        cout << warriorDist << " " << stoneWarrior << " " << attackWarrior << "\n";
    }

    return 0;
}

int sightUp(Coord now, bool isTest) {
    // 시야 범위 설정
    for (int nx = now.x - 1; nx >= 0; nx--) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));
        for (int ny = left; ny <= right; ny++) {
            sightMap[nx][ny] = 1;
        }
    }

    // 바로 위쪽 전사들 확인
    bool object = false;
    for (int nx = now.x - 1; nx >= 0; nx--) {
        if (object) {
            sightMap[nx][now.y] = 0;
        }
        else {
            sightMap[nx][now.y] = 1;
        }

        if (warriorCountGrid[nx][now.y]) {
            object = true;
        }
    }

    // 왼쪽 오른쪽 시야 조정
    for (int nx = now.x - 1; nx > 0; nx--) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));

        // 왼쪽 측면
        for (int ny = left; ny < now.y; ny++) {
            // 이미 제거된 곳 or 전사 뒤
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny]) {
                if (ny > 0) sightMap[nx - 1][ny - 1] = 0; // 왼쪽 위 제거
                sightMap[nx - 1][ny] = 0; // 바로 위 제거
            }
        }

        // 오른쪽 측면
        for (int ny = now.y + 1; ny <= right; ny++) {
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny]) {
                if (ny + 1 < N) sightMap[nx - 1][ny + 1] = 0; // 오른쪽 위 제거
                sightMap[nx - 1][ny] = 0; // 바로 위 제거
            }
        }
    }

    // 전사 수 계산
    int cover = 0;
    for (int nx = now.x - 1; nx >= 0; nx--) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));
        for (int ny = left; ny <= right; ny++) {
            if (sightMap[nx][ny]) {
                cover += warriorCountGrid[nx][ny];
            }
        }
    }

    return cover;
}

int sightDown(Coord now, bool isTest) {
    // 시야 범위 설정
    for (int nx = now.x + 1; nx < N; nx++) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));
        for (int ny = left; ny <= right; ny++) {
            sightMap[nx][ny] = 1;
        }
    }

    // 바로 아래쪽 전사들 확인
    bool object = false;
    for (int nx = now.x + 1; nx < N; nx++) {
        if (object) {
            sightMap[nx][now.y] = 0;
        }
        else {
            sightMap[nx][now.y] = 1;
        }

        if (warriorCountGrid[nx][now.y] > 0) {
            object = true;
        }
    }

    // 왼쪽 오른쪽 시야 조정
    for (int nx = now.x + 1; nx < N - 1; nx++) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));

        // 왼쪽 측면
        for (int ny = left; ny < now.y; ny++) {
            // 이미 제거된 곳 or 전사 뒤
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny] > 0) {
                if (ny > 0) sightMap[nx + 1][ny - 1] = 0; // 왼쪽 아래 제거
                sightMap[nx + 1][ny] = 0; // 바로 아래 제거
            }
        }

        // 오른쪽 측면
        for (int ny = now.y + 1; ny <= right; ny++) {
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny] > 0) {
                if (ny + 1 < N) sightMap[nx + 1][ny + 1] = 0; // 오른쪽 아래 제거
                sightMap[nx + 1][ny] = 0; // 바로 아래 제거
            }
        }
    }

    // 전사 수 계산
    int cover = 0;
    for (int nx = now.x + 1; nx < N; nx++) {
        int left = max(0, now.y - abs(nx - now.x));
        int right = min(N - 1, now.y + abs(nx - now.x));
        for (int ny = left; ny <= right; ny++) {
            if (sightMap[nx][ny]) {
                cover += warriorCountGrid[nx][ny];
            }
        }
    }

    return cover;
}

int sightLeft(Coord now, bool isTest) {
    // 시야 범위 설정
    for (int ny = now.y - 1; ny >= 0; ny--) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));
        for (int nx = up; nx <= down; nx++) {
            sightMap[nx][ny] = 1;
        }
    }

    // 바로 뒤쪽 전사들 확인
    bool object = false;
    for (int ny = now.y - 1; ny >= 0; ny--) {
        if (object) {
            sightMap[now.x][ny] = 0;
        }
        else {
            sightMap[now.x][ny] = 1;
        }

        if (warriorCountGrid[now.x][ny] > 0) {
            object = true;
        }
    }

    // 위쪽 아래쪽 시야 조정
    for (int ny = now.y - 1; ny > 0; ny--) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));

        // 위쪽 측면
        for (int nx = up; nx < now.x; nx++) {
            // 이미 제거된 곳 or 전사 뒤
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny] > 0) {
                if (nx > 0) sightMap[nx - 1][ny - 1] = 0; // 위쪽의 왼쪽 제거
                sightMap[nx][ny - 1] = 0; // 바로 왼쪽 제거
            }
        }

        // 아래쪽 측면
        for (int nx = now.x + 1; nx <= down; nx++) {
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny] > 0) {
                if (nx + 1 < N) sightMap[nx + 1][ny - 1] = 0; // 아래쪽 왼쪽 제거
                sightMap[nx][ny - 1] = 0; // 바로 왼쪽 제거
            }
        }
    }

    // 전사 수 계산
    int cover = 0;
    for (int ny = now.y - 1; ny >= 0; ny--) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));
        for (int nx = up; nx <= down; nx++) {
            if (sightMap[nx][ny]) {
                cover += warriorCountGrid[nx][ny];
            }
        }
    }

    return cover;
}

int sightRight(Coord now, bool isTest) {
    // 시야 범위 설정
    for (int ny = now.y + 1; ny < N; ny++) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));
        for (int nx = up; nx <= down; nx++) {
            sightMap[nx][ny] = 1;
        }
    }

    // 바로 뒤쪽 전사들 확인
    bool object = false;
    for (int ny = now.y + 1; ny < N; ny++) {
        if (object) {
            sightMap[now.x][ny] = 0;
        }
        else {
            sightMap[now.x][ny] = 1;
        }

        if (warriorCountGrid[now.x][ny]) {
            object = true;
        }
    }

    // 위쪽 아래쪽 시야 조정
    for (int ny = now.y + 1; ny < N-1; ny++) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));

        // 위쪽 측면
        for (int nx = up; nx < now.x; nx++) {
            // 이미 제거된 곳 or 전사 뒤
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny]) {
                if (nx > 0) sightMap[nx - 1][ny + 1] = 0; // 위쪽의 오른쪽 제거
                sightMap[nx][ny + 1] = 0; // 바로 오른쪽 제거
            }
        }

        // 아래쪽 측면
        for (int nx = now.x + 1; nx <= down; nx++) {
            if (sightMap[nx][ny] == 0 || warriorCountGrid[nx][ny] > 0) {
                if (nx + 1 < N) sightMap[nx + 1][ny + 1] = 0; // 아래쪽 오른쪽 제거
                sightMap[nx][ny + 1] = 0; // 바로 오른쪽 제거
            }
        }
    }

    // 전사 수 계산
    int cover = 0;
    for (int ny = now.y + 1; ny < N; ny++) {
        int up = max(0, now.x - abs(ny - now.y));
        int down = min(N - 1, now.x + abs(ny - now.y));
        for (int nx = up; nx <= down; nx++) {
            if (sightMap[nx][ny]) {
                cover += warriorCountGrid[nx][ny];
            }
        }
    }

    return cover;
}
