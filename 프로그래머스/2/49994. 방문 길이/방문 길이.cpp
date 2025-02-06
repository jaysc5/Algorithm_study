#include <string>
#include <iostream>

using namespace std;


int dx[4] = {0, 1, 0,-1};
int dy[4] = {1, 0, -1,0};

int solution(string dirs) {
    int x=5,y=5;
    int dir=0;
    int answer = 0;
    int visited[11][11][4] = {false,};

    for(int i=0;i<dirs.size();i++){
        if (dirs[i]=='U') dir=0;
        else if(dirs[i]=='R') dir=1;
        else if(dirs[i]=='D') dir=2;
        else if(dirs[i]=='L') dir=3;
        
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(0>nx || nx>10 || 0>ny || ny>10) continue;
        int reverse_dir = (dir+2)%4;
        if(!visited[x][y][dir] && !visited[nx][ny][reverse_dir]){
            answer++;
            visited[x][y][dir]=true;
            visited[nx][ny][reverse_dir] =true;
        }
        x=nx;
        y=ny;
    }    

    return answer;
}