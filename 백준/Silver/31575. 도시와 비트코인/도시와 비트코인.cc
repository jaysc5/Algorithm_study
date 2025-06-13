#include<iostream>
using namespace std;

int main(void) {
    int map[305][305] = { 0, };
    bool dp[305][305] = { false, };

    int n, m;
    cin >> n >> m;

    for (int j = 0; j < m; j++) {         // 세로
        for (int i = 0; i < n; i++) {     // 가로
            cin >> map[i][j];
        }
    }

    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 || dp[i][j] == false) continue;

            if (i + 1 < n && map[i + 1][j] == 1) dp[i + 1][j] = true;
            if (j + 1 < m && map[i][j + 1] == 1) dp[i][j + 1] = true;
        }
    }

    if (dp[n - 1][m - 1]) cout << "Yes";
    else cout << "No";

    return 0;
}
