#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subarray;
    
    for (const auto &cmd : commands) {
        subarray.assign(array.begin() + (cmd[0]-1), array.begin() + cmd[1]);
        sort(subarray.begin(), subarray.end());
        answer.push_back(subarray[cmd[2]-1]);
    }
    
    return answer;
}