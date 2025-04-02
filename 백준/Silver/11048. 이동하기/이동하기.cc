#include <iostream>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

int map[1001][1001];
int candy[1001][1001];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            candy[i][j] = max(max(candy[i - 1][j], candy[i][j - 1]), candy[i - 1][j - 1]) + map[i][j];
        }
    }
    
    cout << candy[N][M];

    return 0;;
}
