#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for (auto st : intStrs){
        int tmp = stoi(st.substr(s, l));
        if (tmp > k)
            answer.push_back(tmp);
    }
    return answer;
}