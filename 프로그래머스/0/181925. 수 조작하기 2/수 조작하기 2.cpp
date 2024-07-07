#include <string>
#include <vector>
#include <map>

using namespace std;
map <int, char> m = {{1, 'w'}, {-1, 's'}, {10, 'd'}, {-10, 'a'}};
string solution(vector<int> numLog) {
    string answer = "";
    for(int i=0; i<numLog.size()-1; i++)
        answer += m[numLog[i+1] - numLog[i]];
    return answer;
}