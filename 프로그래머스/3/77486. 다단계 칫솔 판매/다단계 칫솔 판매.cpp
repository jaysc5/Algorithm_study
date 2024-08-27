#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, string> parent;
    unordered_map<string, int> total;
    vector<int> answer;

    for (size_t i=0; i<enroll.size(); i++)
        parent[enroll[i]] = referral[i];
    
    for (const auto &name : enroll)
        total[name] = 0;
    
    for (size_t i=0; i<seller.size(); i++){
        string cur_name = seller[i];
        int money = amount[i] * 100;
        
        while (money>0 && cur_name != "-"){
            int profit = money / 10;
            total[cur_name] += money - profit;
            
            if (parent.find(cur_name) != parent.end()){
                cur_name = parent[cur_name];
            }
            else break;
            
            money = profit;
        }
    }
    
    for (const auto name : enroll)
        answer.push_back(total[name]);
    
    return answer;
}