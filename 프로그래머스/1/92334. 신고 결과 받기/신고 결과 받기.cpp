#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> report_dict;
    unordered_set<string> uniq_report;
    unordered_map<string, vector<string>> report_user;
    
    for(string rp : report) uniq_report.insert(rp);
    
    for (string rp : uniq_report) {
        stringstream ss(rp);
        string id, rpid;
        ss >> id >> rpid;
        report_dict[rpid] += 1;
        report_user[id].push_back(rpid);
    }
    
    for (string id : id_list){
        answer.push_back(0);
        for (string rpid : report_user[id]){
            if (report_dict[rpid] >= k)
                answer.back()++;
        }
    }

    return answer;
}