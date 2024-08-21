#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> users;
    
    for (int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string state, uid, name;
        ss >> state >> uid;

        if (state == "Enter" or state == "Change"){
            ss >> name;
            users[uid] = name;
        }
    }
    
    for (int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string state, uid;
        ss >> state >> uid;

        if (state == "Enter"){
            answer.push_back(users[uid] + "님이 들어왔습니다.");
        }
        else if (state == "Leave"){
            answer.push_back(users[uid] + "님이 나갔습니다.");
        }
    }
    return answer;
}