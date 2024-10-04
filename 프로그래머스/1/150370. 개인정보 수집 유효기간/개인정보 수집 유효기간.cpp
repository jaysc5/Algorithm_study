#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int cal(string today) {
    string year = today.substr(0, 4);
    string month = today.substr(5, 2);
    string day = today.substr(8, 2);
    return stoi(year)*12*28 + stoi(month)*28 + stoi(day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> t;
    int todays = cal(today);

    for (int i=0; i<terms.size(); i++) {
        t[terms[i][0]] = stoi(terms[i].substr(2, terms[i].size()-2))*28;
    }
    
    for (int i=0; i<privacies.size(); i++) {
        char type = privacies[i][11];
        int days = cal(privacies[i]) + t[type] -1;
        if (todays > days) answer.push_back(i+1);
    }
    return answer;
}