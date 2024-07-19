#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int x = 0, y = 0;
    char flag = 'r';
    for (int i=1; i<=n*n; i++){
        answer[x][y] = i;
        if (flag=='r'){
            y += 1;
            if (y==n-1 or answer[x][y+1]!=0) flag = 'd';
        }
        else if (flag=='d'){
            x += 1;
            if (x==n-1 or answer[x+1][y]!=0) flag = 'l';
        }
        else if (flag=='l'){
            y -= 1;
            if (y==0 or answer[x][y-1]!=0) flag = 'u';
        }
        else if (flag=='u'){
            x -= 1;
            if (x==0 or answer[x-1][y]!=0) flag = 'r';
        }
    }
    return answer;
}