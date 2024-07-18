#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> answer(31,0);
    for(string st : strArr)
        answer[st.size()]++;
    return *max_element(answer.begin(), answer.end());
}