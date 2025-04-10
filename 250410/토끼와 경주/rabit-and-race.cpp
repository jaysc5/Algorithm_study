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

    bool operator<(const Rabbit& b) const {
        if (jumpcount != b.jumpcount) return jumpcount > b.jumpcount;
        if ((x + y) != (b.x + b.y)) return (x + y) > (b.x + b.y);
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return pid > b.pid;
    }

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
long long total_sum;

bool isRange(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= M;
}

void initRace() {
    cin >> N >> M >> P;
    for (int i = 0; i < P; i++) {
        cin >> id[i] >> dist[i];

        id_to_index[id[i]] = i;
        nowCoord[i] = { 1,1 };
    }
}

Coord getNextPosition(int x, int y, int d, int dist) {
    int len = (d % 2 == 0) ? M : N;  // 좌우면 열(M), 상하면 행(N)
    int pos = (d % 2 == 0) ? y : x;
    int move = dist;
    int dir = (d == 1 || d == 0) ? 1 : -1;  // 우/하: +1, 좌/상: -1
    int total = (len - 1) * 2;
    move %= total;

    for (int i = 0; i < move; i++) {
        pos += dir;
        if (pos < 1 || pos > len) {
            dir *= -1;
            pos += 2 * dir;
        }
    }

    return (d % 2 == 0) ? Coord{ x, pos } : Coord{ pos, y };
}

void startRace() {
    int k, s;
    cin >> k >> s;

    priority_queue<Rabbit> race;

    for (int i = 0; i < P; i++) {
        race.push({ id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] });
        kturncheck[i] = false;
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

        total_sum += nowMove.x + nowMove.y;
        point[idx] -= nowMove.x + nowMove.y;
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
        maxPoint = max(maxPoint, total_sum + point[i]);
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

