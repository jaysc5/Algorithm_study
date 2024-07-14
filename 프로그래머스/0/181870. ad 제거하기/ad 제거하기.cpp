#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for (auto st: strArr){
        if (st.rfind("ad")==-1) answer.push_back(st);
    }
    return answer;
}