#include <iostream>

using namespace std;

int board[19][19] = {0,};
int dx[4] = { -1, 0, 1, 1};
int dy[4] = { 1, 1, 1, 0 };
int answer[3] = {0,};

int main(){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if (board[i][j]==0) continue;

            int type = board[i][j];

            for(int d=0;d<4;d++){
                for(int k=0;k<5;k++){
                    int nx = i + k * dx[d];
                    int ny = j + k * dy[d];

                    if(0 > nx || nx >= 19 || 0 > ny || ny >= 19)
                        break;
                    if(board[nx][ny]==0 || board[nx][ny]!= type)
                        break;

                    if (k==4){
                        if (board[nx+dx[d]][ny+dy[d]] == type)
                            break;
                        else if (board[i-dx[d]][j-dy[d]] == type)
                            break;
                        else{
                            answer[0] = type;
                            answer[1] = i+1;
                            answer[2] = j+1;
                        }
                    }
                }
            }
        }
    }

    if (answer[0]==0){
        cout << answer[0] << "\n";
    }
    else{
        cout << answer[0] << "\n";
        cout << answer[1] << " " << answer[2]<< "\n";
    }
    return 0;
}