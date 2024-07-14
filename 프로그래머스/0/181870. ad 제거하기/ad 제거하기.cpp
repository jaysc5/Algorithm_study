#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for (auto st: strArr){
        if (st.rfind("ad")==string::npos) answer.push_back(st);
    }
    return answer;
}