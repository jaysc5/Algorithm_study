#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> want_list;
    int answer = 0;
    
    for (int i=0; i<want.size(); i++) {
        want_list[want[i]] = number[i];
    }
    
    for (int i=0; i<discount.size()-9; i++){
        unordered_map<string, int> discount_list;
        
        for (int j=i; j < i+10; j++)
            discount_list[discount[j]]++;
        
        if (want_list == discount_list) answer++;
    }
    
    return answer;
}