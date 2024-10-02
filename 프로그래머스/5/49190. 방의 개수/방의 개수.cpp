#include <string>
#include <vector>
#include <map>
using namespace std;

int dx[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1,  0,  1};

int solution(vector<int> arrows) {
    int answer = 0;
    int x=0, y=0;
    map<pair<int, int>, bool> nodevisited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edgevisited;
    nodevisited[{x, y}] = true;
    
    for (auto a : arrows) {
        for (int i=0; i<2; i++) {
            int nx = x + dx[a];
            int ny = y + dy[a];
            if (nodevisited[{nx, ny}]==true and edgevisited[{{x, y}, {nx, ny}}]==false)
                answer++;
            else nodevisited[{nx, ny}] = true;
            edgevisited[{{x, y}, {nx, ny}}] = true;
            edgevisited[{{nx, ny}, {x, y}}] = true;
            x = nx, y = ny;
        }
    }
    return answer;
}