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

    struct cmpK {
        bool operator()(Rabbit a, Rabbit b) const {
            if ((a.x + a.y) != (b.x + b.y)) return (a.x + a.y) < (b.x + b.y);
            if (a.x != b.x) return a.x < b.x;
            if (a.y != b.y) return a.y < b.y;
            return a.pid < b.pid;
        }
    };
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
        jumpCount[0] = 0;
    }
}

void startRace() {
    int k, s;
    cin >> k >> s;

    priority_queue<Rabbit, vector<Rabbit>, Rabbit::cmpRace> race;
    priority_queue<Coord, vector<Coord>, Coord::cmp> turnmove;
    priority_queue<Rabbit, vector<Rabbit>, Rabbit::cmpK> kturn;

    for (int i = 0; i < P; i++) {
        race.push({ id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] });
    }


    while (k--) {
        Rabbit move = race.top();
        race.pop();
        kturncheck[id_to_index[move.pid]] = true;

        while (!turnmove.empty()) turnmove.pop();

        for (int i = 0; i < 4; i++) {
            int nx = move.x;
            int ny = move.y;
            int nd = i;
            for (int j = 0; j < dist[id_to_index[move.pid]]; j++) {
                nx += dx[nd];
                ny += dy[nd];

                if (!isRange(nx, ny)) {
                    nd = (nd + 2) % 4;
                    nx += 2 * dx[nd];
                    ny += 2 * dy[nd];
                }
            }
            turnmove.push({ nx, ny });
        }

        Coord nowMove = turnmove.top();
        move.x = nowMove.x;
        move.y = nowMove.y;
        move.jumpcount++;
        race.push(move);

        for (int i = 0; i < P; i++) {
            if (id_to_index[move.pid] != i) {
                point[i] += nowMove.x + nowMove.y;
            }
        }
    }

    while (!race.empty()) {
        Rabbit now = race.top();
        race.pop();

        nowCoord[id_to_index[now.pid]] = { now.x, now.y };
        jumpCount[id_to_index[now.pid]] = now.jumpcount;
        kturn.push(now);
    }

    while (!kturn.empty()) {
        Rabbit kturnbest = kturn.top();
        kturn.pop();

        if (kturncheck[id_to_index[kturnbest.pid]] == false) continue;

        point[id_to_index[kturnbest.pid]] += s;
        break;
    }
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