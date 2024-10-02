#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    for (auto &e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    vector<int> distances(n+1, -1);
    distances[1] = 0;
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next : graph[cur]) {
            if (distances[next] == -1) {
                distances[next] = distances[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int answer = 0;
    int far = *max_element(distances.begin(), distances.end());
    for (int i=0; i<distances.size(); i++) {
        if (distances[i] == far) answer++;
    }
    return answer;
}