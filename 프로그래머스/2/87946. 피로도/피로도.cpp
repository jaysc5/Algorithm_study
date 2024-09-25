#include <string>
#include <vector>

using namespace std;

int maxDepth = 0;
bool visited[8] = {false,};

void dfs(int depth, int k, vector<vector<int>> &dungeons) {
    if (maxDepth < depth)
        maxDepth = depth;
    
    for (int i=0; i<dungeons.size(); i++) {
        if (visited[i] or dungeons[i][0] > k)
            continue;
        
        visited[i] = true;
        dfs(depth+1, k-dungeons[i][1], dungeons);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return maxDepth;
}