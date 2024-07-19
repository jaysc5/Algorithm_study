#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    for (int i=0; i<=k & i<board.size(); i++){
        for (int j=0; j<=k-i & j<board[0].size(); j++){
                answer += board[i][j];
        }
    }
    return answer;
}