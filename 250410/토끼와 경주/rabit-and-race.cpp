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

// 토끼를 위로 이동시킵니다.
Rabbit GetUpRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit up_rabbit = cur_rabbit;
    dis %= 2 * (N - 1);

    if (dis >= up_rabbit.x - 1) {
        dis -= (up_rabbit.x - 1);
        up_rabbit.x = 1;
    }
    else {
        up_rabbit.x -= dis;
        dis = 0;
    }

    if (dis >= N - up_rabbit.x) {
        dis -= (N - up_rabbit.x);
        up_rabbit.x = N;
    }
    else {
        up_rabbit.x += dis;
        dis = 0;
    }

    up_rabbit.x -= dis;

    return up_rabbit;
}

// 토끼를 아래로 이동시킵니다.
Rabbit GetDownRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit down_rabbit = cur_rabbit;
    dis %= 2 * (N - 1);

    if (dis >= N - down_rabbit.x) {
        dis -= (N - down_rabbit.x);
        down_rabbit.x = N;
    }
    else {
        down_rabbit.x += dis;
        dis = 0;
    }

    if (dis >= down_rabbit.x - 1) {
        dis -= (down_rabbit.x - 1);
        down_rabbit.x = 1;
    }
    else {
        down_rabbit.x -= dis;
        dis = 0;
    }

    down_rabbit.x += dis;

    return down_rabbit;
}

// 토끼를 왼쪽으로 이동시킵니다.
Rabbit GetLeftRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit left_rabbit = cur_rabbit;
    dis %= 2 * (M - 1);

    if (dis >= left_rabbit.y - 1) {
        dis -= (left_rabbit.y - 1);
        left_rabbit.y = 1;
    }
    else {
        left_rabbit.y -= dis;
        dis = 0;
    }

    if (dis >= M - left_rabbit.y) {
        dis -= (M - left_rabbit.y);
        left_rabbit.y = M;
    }
    else {
        left_rabbit.y += dis;
        dis = 0;
    }

    left_rabbit.y -= dis;

    return left_rabbit;
}

// 토끼를 오른쪽으로 이동시킵니다.
Rabbit GetRightRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit right_rabbit = cur_rabbit;
    dis %= 2 * (M - 1);

    if (dis >= M - right_rabbit.y) {
        dis -= (M - right_rabbit.y);
        right_rabbit.y = M;
    }
    else {
        right_rabbit.y += dis;
        dis = 0;
    }

    if (dis >= right_rabbit.y - 1) {
        dis -= (right_rabbit.y - 1);
        right_rabbit.y = 1;
    }
    else {
        right_rabbit.y -= dis;
        dis = 0;
    }

    right_rabbit.y += dis;

    return right_rabbit;
}

bool Cmp(Rabbit a, Rabbit b) {
    if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.pid < b.pid;
}

void startRace() {
    int k, s;
    cin >> k >> s;

    priority_queue<Rabbit> race;
    for (int i = 0; i < P; i++) {
        Rabbit new_rabbit;
        new_rabbit.x = nowCoord[i].x;
        new_rabbit.y = nowCoord[i].y;
        new_rabbit.jumpcount = jumpCount[i];
        new_rabbit.pid = id[i];

        race.push(new_rabbit);

        //race.emplace(Rabbit{ id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] });
        kturncheck[i] = false;
    }

    Coord::cmp cmpCoord;
    while (k--) {
        //Rabbit move = race.top(); race.pop();
        //int idx = id_to_index[move.pid];
        //kturncheck[idx] = true;

        //Coord nowMove = { -1, -1 };
        //for (int d = 0; d < 4; d++) {
        //    Coord cand = getNextPosition(move.x, move.y, d, dist[idx]);
        //    if (cmpCoord(nowMove, cand)) nowMove = cand;
        //}

        //move.x = nowMove.x;
        //move.y = nowMove.y;
        //move.jumpcount++;
        //race.emplace(move);

        //total_sum += (nowMove.x + nowMove.y);
        //point[idx] -= (nowMove.x + nowMove.y);
        //nowCoord[idx] = { nowMove.x, nowMove.y };
        //jumpCount[idx] = move.jumpcount;

        Rabbit cur_rabbit = race.top(); race.pop();

        // 해당 토끼를 상, 하, 좌, 우 4개의 방향으로 이동시킵니다.
        // 각각의 방향으로 이동시킨 후 최종 위치를 구하고
        // 가장 시작점으로부터 멀리 있는 위치를 찾아줍니다.
        int dis = dist[id_to_index[cur_rabbit.pid]];
        Rabbit nex_rabbit = cur_rabbit;
        nex_rabbit.x = 0;
        nex_rabbit.y = 0;


        // 토끼를 위로 이동시킵니다.
        Rabbit up_rabbit = GetUpRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, up_rabbit)) nex_rabbit = up_rabbit;


        // 토끼를 아래로 이동시킵니다.
        Rabbit down_rabbit = GetDownRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, down_rabbit)) nex_rabbit = down_rabbit;


        // 토끼를 왼쪽으로 이동시킵니다.
        Rabbit left_rabbit = GetLeftRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, left_rabbit)) nex_rabbit = left_rabbit;


        // 토끼를 오른쪽으로 이동시킵니다.
        Rabbit right_rabbit = GetRightRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, right_rabbit)) nex_rabbit = right_rabbit;


        // 토끼의 점프 횟수를 갱신해주고, priority queue에 다시 집어넣습니다.
        nex_rabbit.jumpcount++;
        race.push(nex_rabbit);

        // 실제 point, jump_cnt 배열에도 값을 갱신해줍니다.
        int nex_idx = id_to_index[nex_rabbit.pid];
        nowCoord[nex_idx] = { nex_rabbit.x, nex_rabbit.y };
        jumpCount[nex_idx]++;

        // 토끼가 달렸는지 여부를 체크해줍니다.
        kturncheck[nex_idx] = true;

        // 토끼가 받는 점수는 (현재 뛴 토끼)만 (r + c)만큼 점수를 빼주고,
        // 모든 토끼(total_sum)에게 (r + c)만큼 점수를 더해줍니다.
        // 최종적으로 i번 토끼가 받는 점수는 result[i] + total_sum이 됩니다.
        point[nex_idx] -= (nex_rabbit.x + nex_rabbit.y);
        total_sum += (nex_rabbit.x + nex_rabbit.y);

    }

    //Rabbit best = { 0, 0, 0, 0 };
    //for (int i = 0; i < P; i++) {
    //    if (!kturncheck[i]) continue;
    //    Rabbit now = { id[i], nowCoord[i].x, nowCoord[i].y, jumpCount[i] };
    //    if (cmp(now, best)) best = now;
    //}
    //point[id_to_index[best.pid]] += s;
    Rabbit bonus_rabbit;
    bonus_rabbit.x = 0;
    bonus_rabbit.y = 0;
    while (!race.empty()) {
        Rabbit cur_rabbit = race.top(); race.pop();

        // 달리지 않은 토끼는 스킵합니다.
        if (!kturncheck[id_to_index[cur_rabbit.pid]]) continue;

        if (Cmp(bonus_rabbit, cur_rabbit))
            bonus_rabbit = cur_rabbit;
    }

    // 해당 토끼에게 bonus만큼 점수를 추가해줍니다.
    point[id_to_index[bonus_rabbit.pid]] += s;

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
