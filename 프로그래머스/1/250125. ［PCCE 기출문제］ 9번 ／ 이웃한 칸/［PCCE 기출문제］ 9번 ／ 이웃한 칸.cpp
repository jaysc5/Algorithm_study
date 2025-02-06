#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    string color = board[h][w];
    
    for(int i=0;i<4;i++){
        int nx = h+dx[i];
        int ny = w+dy[i];
        
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        
        if(board[nx][ny] == color) answer++;
    }
    return answer;
}