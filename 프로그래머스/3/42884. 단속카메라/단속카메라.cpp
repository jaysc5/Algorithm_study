#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int Cam_Pos = routes[0][1];
    
    for (int i = 1; i < routes.size(); i++)    {
        if (routes[i][1] < Cam_Pos)
            Cam_Pos = routes[i][1];
        else if (routes[i][0] > Cam_Pos) {
            answer++;
            Cam_Pos = routes[i][1];
        }
    }
    
    return answer;
}