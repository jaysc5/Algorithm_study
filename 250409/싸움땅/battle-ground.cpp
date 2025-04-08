#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int x, y, d;
    int initpower;
    int gun;
    bool winning;
    int point;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, K;
int gunMap[20][20]; // 0(없음) 1(있음)
vector<vector<int>> gun_in_map;
vector<vector<int>> player_in_map;

int playerMap[20][20]; // -1(없음) 0~M-1 player index
vector<Info> playersInfo;

void getGun(int i) {
    Info nowPlayer = playersInfo[i];
    int nx = nowPlayer.x;
    int ny = nowPlayer.y;

    if (gunMap[nx][ny] == 1) {
        if (!gun_in_map[N * nx + ny].empty()) {
            gun_in_map[N * nx + ny].push_back(nowPlayer.gun);
            sort(gun_in_map[N * nx + ny].begin(), gun_in_map[N * nx + ny].end());
            playersInfo[i].gun = gun_in_map[N * nx + ny].back();
            gun_in_map[N * nx + ny].pop_back();
        }

        //for (int g = 0; g < gun_in_map[N * nx + ny].size(); g++) {
        //    if (nowPlayer.gun < gun_in_map[N * nx + ny][g]) {
        //        int tmp = gun_in_map[N * nx + ny][g];
        //        gun_in_map[N * nx + ny].erase(gun_in_map[N * nx + ny].begin() + g);
        //        gun_in_map[N * nx + ny].push_back(nowPlayer.gun);
        //        playersInfo[i].gun = tmp;
        //    }
        //}
    }
}

void moveLosePlayer(int i) {
    Info nowPlayer = playersInfo[i];

    int nx = nowPlayer.x + dx[nowPlayer.d];
    int ny = nowPlayer.y + dy[nowPlayer.d];

    for (int k = 0; k < 4; k++) {
        if (playerMap[nx][ny] != -1 || nx < 0 || nx >= N || ny < 0 || ny >= N) {
            nowPlayer.d = (nowPlayer.d + 1) % 4;
            nx = nowPlayer.x + dx[nowPlayer.d];
            ny = nowPlayer.y + dy[nowPlayer.d];
            if (playerMap[nx][ny] == -1) break;
        }
    }

    playersInfo[i].x = nx;
    playersInfo[i].y = ny;
    playersInfo[i].d = nowPlayer.d;
    playerMap[nx][ny] = i;
}

void actionLosePlayer(int i) {
    Info losePlayer = playersInfo[i];
    int nx = losePlayer.x;
    int ny = losePlayer.y;

    // 총 내려 놓기
    gun_in_map[N * nx + ny].push_back(losePlayer.gun);
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
        if(initpowerA < initpowerB) {
            winPlayer = b;
            losePlayer = a;
        }
        else if (initpowerA > initpowerB) {
            winPlayer = a;
            losePlayer = b;
        }
    }

    // 경험치 획득
    playersInfo[winPlayer].point = playersInfo[winPlayer].point + abs(powerA - powerB);
    playerMap[playersInfo[winPlayer].x][playersInfo[winPlayer].y] = winPlayer;

    // 진 플레이어
    actionLosePlayer(losePlayer);

    // 이긴 플레이어
    actionWinPlayer(winPlayer);
}

void movePlayer(int i) {
    Info nowPlayer = playersInfo[i];

    int nx = nowPlayer.x + dx[nowPlayer.d];
    int ny = nowPlayer.y + dy[nowPlayer.d];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
        nowPlayer.d = (nowPlayer.d + 2) % 4;
        nx = nowPlayer.x + dx[nowPlayer.d];
        ny = nowPlayer.y + dy[nowPlayer.d];
    }

    playerMap[playersInfo[i].x][playersInfo[i].y] = -1;
    playersInfo[i].x = nx;
    playersInfo[i].y = ny;
    playersInfo[i].d = nowPlayer.d;

    if (playerMap[nx][ny] == -1) {
        playerMap[nx][ny] = i;
        getGun(i);
    }
    else {
        fightPlayers(i, playerMap[nx][ny]);
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    gun_in_map.resize(N * N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            playerMap[i][j] = -1;
            cin >> gunMap[i][j];
            if (gunMap[i][j] != 0) {
                gun_in_map[N * i + j].push_back(gunMap[i][j]);
                gunMap[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        x--;
        y--;
        playersInfo.push_back({ x, y, d, s, 0, false, 0 });
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