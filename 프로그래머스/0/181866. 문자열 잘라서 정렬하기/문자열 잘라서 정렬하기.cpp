#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    istringstream ss(myString);
    string buff;
    while (getline(ss, buff, 'x')){
        if (buff.size()!=0) answer.push_back(buff);
    }
    sort(answer.begin(),answer.end());
    return answer;
}