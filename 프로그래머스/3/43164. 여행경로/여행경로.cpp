#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001];

bool dfs(string city, int cnt, vector<vector<string>> &tickets) {
    if (cnt == tickets.size()) return true;
    
    for (int i=0; i<tickets.size(); i++) {
        if (tickets[i][0] == city and visited[i] == false) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], cnt+1, tickets)) return true;
            else {
                visited[i] = false;
            }
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs("ICN", 0, tickets);
    return answer;
}