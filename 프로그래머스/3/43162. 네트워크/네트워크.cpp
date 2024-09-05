#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
void dfs(const vector<vector<int>>& computers, int node) {
    visited[node] = true;
    
    for (int i=0; i<computers[node].size(); i++) {
        if (computers[node][i] && !visited[i]) {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited = vector<bool>(computers.size(), false);
    int answer = 0;
    
    for (int i=0; i<computers.size(); i++) {
        if (!visited[i]) {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}