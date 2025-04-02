#include <iostream>

using namespace std;

int MAP[5][5];
pair<int, int> DAT[26];

int dx[4] = { 0, 1,1,-1 };
int dy[4] = { 1, 0,1,1 };

bool check() {
    int bingoCount = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (MAP[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int cnt = 1;
                    for (int n = 0; n < 4; n++) {
                        int nx = i + dx[k] * (n + 1);
                        int ny = j + dy[k] * (n + 1);
                        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) break;
                        if (MAP[nx][ny] != 0) break;
                        cnt++;
                    }
                    if (cnt == 5) bingoCount++;
                }
            }
        }
    }
    if (bingoCount >= 3) return true;
    else return false;
}

int main() {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> MAP[i][j];
            DAT[MAP[i][j]] = { i, j };
        }
    }

    int cnt = 0;;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int n;
            cin >> n;
            cnt++;
            MAP[DAT[n].first][DAT[n].second] = 0;
            if (check()) {
                cout << cnt;
                return 0;
            }
        }
    }

    return 0;
}
