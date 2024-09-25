#include <string>
#include <vector>

using namespace std;
bool checkRow(int prow, int crow) { return prow == crow; }
bool checkDiagonal(int prow, int pcol, int crow, int ccol) {
    return abs(prow-crow) == abs(pcol-ccol);
}

bool checkQueen(const vector<int> &queen, int col, int row) {
    for (int i=0; i<col; i++) {
        if (checkRow(queen[i], row) or checkDiagonal(i, queen[i], col, row))
            return false;
    }
    return true;
}

int placeQueen(vector<int> &queen, int col) {
    int n = queen.size();
    if (col == n) return 1;
    
    int count = 0;
    for (int row=0; row<n; row++) {
        if (checkQueen(queen, col, row)) {
            queen[col] = row;
            count += placeQueen(queen, col+1);
            queen[col] -= 1;
        }
    }
    return count;
}

int solution(int n) {
    vector<int> queen(n, -1);
    
    return placeQueen(queen, 0);
}