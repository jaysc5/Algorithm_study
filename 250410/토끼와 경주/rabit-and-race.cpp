#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Coord {
    int x, y;

    struct cmp {
        bool operator()(Coord a, Coord b) const {
            if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) < (b.x + b.y);
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }
    };
};

struct Rabbit {
    int pid;
    int x, y;
    int jumpcount;

    struct cmpRace {
        bool operator()(Rabbit a, Rabbit b) const {
            if (a.jumpcount != b.jumpcount) return a.jumpcount > b.jumpcount;
            if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) > (b.x + b.y);
            if (a.x != b.x) return a.x > b.x;
            if (a.y != b.y) return a.y > b.y;
            return a.pid > b.pid;
        }
    };
};


bool cmp(Rabbit a, Rabbit b) {
    if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) < (b.x + b.y);
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.pid < b.pid;
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, M, P;
unordered_map<int, int> id_to_index;
int id[2001];
int dist[2001];
long long point[2001];
bool kturncheck[2001];
Coord nowCoord[2001];
int jumpCount[2001];

bool isRange(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= M;
}

void initRace() {
    cin >> N >> M >> P;
    for (int i = 0; i < P; i++) {
        int pid, d;
        cin >> pid >> d;

        id_to_index[pid] = i;
        id[i] = pid;
        dist[i] = d;
        point[i] = 0;
        kturncheck[i] = false;
        nowCoord[i] = { 1,1 };
        jumpCount[i] = 0;
    }
}

// d 방향으로 거리 dist만큼 이동 후 최종 위치 반환
Coord getNextPosition(int x, int y, int d, int dist) {
    int len = (d % 2 == 0) ? M : N; // 좌우면 열 M, 상하면 행 N
    int pos = (d % 2 == 0) ? y : x;

    int move = dist;
    int cur = pos;
    int dir = (d == 1 || d == 0) ? 1 : -1; // 우 또는 하: +1, 좌 또는 상: -1

    // 거리를 이동한 후 위치 계산 (1 ~ len 사이에서 반사 이동)
    int total = (len - 1) * 2;
    move %= total;

    for (int i = 0; i < move; i++) {
        cur += dir;
        if (cur < 1 || cur > len) {
            dir *= -1;
            cur += 2 * dir;
        }
    }

    if (d % 2 == 0) return { x, cur }; // 좌우 이동
    else return { cur, y };            // 상하 이동
}


void startRace() {
    int k, s;
    cin >> k >> s;

    priority_queue<Rabbit, vector<Rabbit>, Rabbit::cmpRace> race;

    for (int i = 0; i < P; i++) {
        race.push({ id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] });
    }


    while (k--) {
        Rabbit move = race.top();
        race.pop();
        int idx = id_to_index[move.pid];

        kturncheck[idx] = true;

        Coord nowMove = { 0, 0 };

        for (int i = 0; i < 4; i++) {
            Coord cand = getNextPosition(move.x, move.y, i, dist[idx]);
            if (Coord::cmp()(nowMove, cand)) {
                nowMove = cand;
            }
        }

        move.x = nowMove.x;
        move.y = nowMove.y;
        move.jumpcount++;
        race.push(move);

        long long addScore = nowMove.x + nowMove.y;
        for (int i = 0; i < P; i++) {
            if (idx != i) {
                point[i] += addScore;
            }
        }
    }

    Rabbit kturnbest = { 0, 0, 0, 0 };

    while (!race.empty()) {
        Rabbit now = race.top();
        race.pop();

        int idx = id_to_index[now.pid];

        nowCoord[idx] = { now.x, now.y };
        jumpCount[idx] = now.jumpcount;

        if (kturncheck[idx] == false) continue;

        if (cmp(now, kturnbest)) kturnbest = now;
    }
    point[id_to_index[kturnbest.pid]] += s;
}

void changeDistance() {
    int pid, l;
    cin >> pid >> l;

    dist[id_to_index[pid]] *= l;
}

void bestRabbit() {
    long long maxPoint = 0;

    for (int i = 0; i < P; i++) {
        maxPoint = max(maxPoint, point[i]);
    }

    cout << maxPoint;
}

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int querytype;
        cin >> querytype;

        if (querytype == 100) {
            initRace();
        }
        else if (querytype == 200) {
            startRace();
        }
        else if (querytype == 300) {
            changeDistance();
        }
        else if (querytype == 400) {
            bestRabbit();
        }
    }

    return 0;
}