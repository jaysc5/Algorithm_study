#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    for(int i=0; i<my_string.size(); i++){
        auto it = find(begin(indices), std::end(indices), i);
        if (it == end(indices)) answer += my_string[i];
    }
    return answer;
}