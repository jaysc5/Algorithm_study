#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Coord {
    int x, y;
    struct cmp {
        bool operator()(const Coord& a, const Coord& b) const {
            if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) < (b.x + b.y);
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }
    };
};

struct Rabbit {
    int pid, x, y, jumpcount;
    bool operator<(const Rabbit& b) const {
        if (jumpcount != b.jumpcount) return jumpcount > b.jumpcount;
        if ((x + y) != (b.x + b.y)) return (x + y) > (b.x + b.y);
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return pid > b.pid;
    }
};

bool cmp(const Rabbit& a, const Rabbit& b) {
    if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) < (b.x + b.y);
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.pid < b.pid;
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M, P;
unordered_map<int, int> id_to_index;
int id[2001];
int dist[2001];
long long point[2001];
bool kturncheck[2001];
Coord nowCoord[2001];
int jumpCount[2001];
long long total_sum = 0;

void initRace() {
    cin >> N >> M >> P;
    for (int i = 0; i < P; i++) {
        cin >> id[i] >> dist[i];
        id_to_index[id[i]] = i;
        nowCoord[i] = { 1, 1 };
        point[i] = 0;
        jumpCount[i] = 0;
    }
    total_sum = 0;
}

Coord getNextPosition(int x, int y, int d, int dist) {
    int len = (d % 2 == 0) ? M : N;
    int pos = (d % 2 == 0) ? y : x;
    int dir = (d == 1 || d == 0) ? 1 : -1;
    int total = (len - 1) * 2;
    int move = dist % total;

    for (int i = 0; i < move; i++) {
        pos += dir;
        if (1 > pos || pos > len) {
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
        race.emplace(Rabbit{ id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] });
        kturncheck[i] = false;
    }

    Coord::cmp cmpCoord;
    while (k--) {
        Rabbit move = race.top(); race.pop();
        int idx = id_to_index[move.pid];
        kturncheck[idx] = true;

        Coord nowMove = { -1, -1 };
        for (int d = 0; d < 4; d++) {
            Coord cand = getNextPosition(move.x, move.y, d, dist[idx]);
            if (cmpCoord(nowMove, cand)) nowMove = cand;
        }

        move.x = nowMove.x;
        move.y = nowMove.y;
        move.jumpcount++;
        race.emplace(move);

        total_sum += (nowMove.x + nowMove.y);
        point[idx] -= (nowMove.x + nowMove.y);
        nowCoord[idx] = { nowMove.x, nowMove.y };
        jumpCount[idx] = move.jumpcount;
    }

    Rabbit best = { 0, 0, 0, 0 };
    for (int i = 0; i < P; i++) {
        if (!kturncheck[i]) continue;
        Rabbit now = { id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] };
        if (cmp(now, best)) best = now;
    }
    point[id_to_index[best.pid]] += s;
}

void changeDistance() {
    int pid, l;
    cin >> pid >> l;
    dist[id_to_index[pid]] *= l;
}

void bestRabbit() {
    long long maxPoint = -21e9;
    for (int i = 0; i < P; i++) {
        maxPoint = max(maxPoint, total_sum + point[i]);
    }
    cout << maxPoint << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 100) initRace();
        else if (cmd == 200) startRace();
        else if (cmd == 300) changeDistance();
        else if (cmd == 400) bestRabbit();
    }

    return 0;
}
