#include <string>
#include <vector>
#include <queue>

#define INF 1e7

using namespace std;
 
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for (auto fare : fares) {
        int src = fare[0], dst = fare[1], fee = fare[2];
        graph[src][dst] = fee;
        graph[dst][src] = fee;
    }
    
    for (int i=1; i<=n; i++)
        graph[i][i] = 0;
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int answer = INF;
    for (int i=1; i<=n; i++) {
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    return answer;
}