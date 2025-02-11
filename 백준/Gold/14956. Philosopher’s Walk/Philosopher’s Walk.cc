#include <iostream>
using namespace std;

int N, M, x, y;

void findLoc(int n, int m) {
    if (n == 2) {
        x = (m == 0 || m == 1) ? 1 : 2;
        y = (m == 0 || m == 3) ? 1 : 2;
        return;
    }

    n /= 2;
    findLoc(n, m % (n * n));

    switch (m / (n * n)) {
        int tmp;
    case 0:
        tmp = x;
        x = y;
        y = tmp;
        break;
    case 1:
        y += n;
        break;
    case 2:
        x += n;
        y += n;
        break;
    case 3:
        tmp = y;
        y = n + 1 - x;
        x = 2 * n + 1 - tmp;
        break;
    default:
        throw;
    }
}

int main() {
    cin >> N >> M;
    findLoc(N, M - 1);
    cout << x << ' ' << y;
}
