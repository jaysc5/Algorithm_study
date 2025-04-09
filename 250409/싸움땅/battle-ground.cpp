#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int x, y, d;
    int initpower;
    int gun;
    int point;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, K;
vector<int> gun_in_map[20][20];
int playerMap[20][20]; // -1(없음) 0~M-1 player index
vector<Info> playersInfo;

void getGun(int i) {
    Info nowPlayer = playersInfo[i];
    int nx = nowPlayer.x;
    int ny = nowPlayer.y;

    if (gun_in_map[nx][ny].size() > 0) {
        gun_in_map[nx][ny].push_back(nowPlayer.gun);
        sort(gun_in_map[nx][ny].begin(), gun_in_map[nx][ny].end());
        playersInfo[i].gun = gun_in_map[nx][ny].back();
        gun_in_map[nx][ny].pop_back();
    }
}

void moveLosePlayer(int i) {
    Info nowPlayer = playersInfo[i];

    int nextD, nx, ny;

    for (int k = 0; k < 4; k++) {
        nextD = (nowPlayer.d + k) % 4;
        nx = nowPlayer.x + dx[nextD];
        ny = nowPlayer.y + dy[nextD];
        if (playerMap[nx][ny] == -1 && !(nx < 0 || nx >= N || ny < 0 || ny >= N)) {
            break;
        }
    }


    playersInfo[i].x = nx;
    playersInfo[i].y = ny;
    playersInfo[i].d = nextD;
    playerMap[nx][ny] = i;
}

void actionLosePlayer(int i) {
    Info losePlayer = playersInfo[i];
    int nx = losePlayer.x;
    int ny = losePlayer.y;

    // 총 내려 놓기
    gun_in_map[nx][ny].push_back(losePlayer.gun);
    playersInfo[i].gun = 0;

    // 이동
    moveLosePlayer(i);
    getGun(i);
}

void actionWinPlayer(int i) {
    // 총 내려놓고 획득
    getGun(i);
}

void fightPlayers(int a, int b) {
    int initpowerA = playersInfo[a].initpower;
    int initpowerB = playersInfo[b].initpower;
    int powerA = playersInfo[a].initpower + playersInfo[a].gun;
    int powerB = playersInfo[b].initpower + playersInfo[b].gun;
    int winPlayer = 0, losePlayer = 0;

    if (powerA < powerB) {
        winPlayer = b;
        losePlayer = a;
    }
    else if (powerA > powerB) {
        winPlayer = a;
        losePlayer = b;
    }
    else {
        if (initpowerA < initpowerB) {
            winPlayer = b;
            losePlayer = a;
        }
        else if (initpowerA > initpowerB) {
            winPlayer = a;
            losePlayer = b;
        }
    }

    // 경험치 획득
    playersInfo[winPlayer].point += abs(powerA - powerB);
    playerMap[playersInfo[winPlayer].x][playersInfo[winPlayer].y] = winPlayer;

    // 진 플레이어
    actionLosePlayer(losePlayer);

    // 이긴 플레이어
    actionWinPlayer(winPlayer);
}

void movePlayer(int i) {
    Info nowPlayer = playersInfo[i];
    playerMap[nowPlayer.x][nowPlayer.y] = -1;

    int nextD = nowPlayer.d;
    int nx = nowPlayer.x + dx[nowPlayer.d];
    int ny = nowPlayer.y + dy[nowPlayer.d];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
        nextD = (nowPlayer.d + 2) % 4;
        nx = nowPlayer.x + dx[nextD];
        ny = nowPlayer.y + dy[nextD];
    }

    playersInfo[i].x = nx;
    playersInfo[i].y = ny;
    playersInfo[i].d = nextD;

    if (playerMap[nx][ny] == -1) {
        playerMap[nx][ny] = i;
        getGun(i);
    }
    else {
        int personinmap = playerMap[nx][ny];
        playerMap[nx][ny] = -1;
        fightPlayers(i, personinmap);
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            playerMap[i][j] = -1;

            int tmp;
            cin >> tmp;
            if (tmp != 0) {
                gun_in_map[i][j].push_back(tmp);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        x--;
        y--;
        playersInfo.push_back({ x, y, d, s, 0, 0 });
        playerMap[x][y] = i;
    }

    while (K--) {
        for (int i = 0; i < M; i++) {
            movePlayer(i);
        }
    }

    for (int i = 0; i < M; i++) {
        cout << playersInfo[i].point << " ";
    }
    return 0;
}
