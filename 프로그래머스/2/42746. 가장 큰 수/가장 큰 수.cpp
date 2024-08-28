#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string &a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    for (int num : numbers)
        tmp.push_back(to_string(num));
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    if (tmp[0] == "0") return "0";
    
    for (string num : tmp)
        answer += num;
    return answer;
}