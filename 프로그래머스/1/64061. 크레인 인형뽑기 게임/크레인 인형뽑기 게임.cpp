#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    
    for (int idx : moves){
        for (int i=0; i<board.size(); i++){
            if (board[i][idx-1] != 0){
                if (!stk.empty() && board[i][idx-1] == stk.top()){
                    stk.pop();
                    answer += 2;
                }
                else
                    stk.push(board[i][idx-1]);
                board[i][idx-1] = 0;
                break;
            }
        }
    }
    return answer;
}