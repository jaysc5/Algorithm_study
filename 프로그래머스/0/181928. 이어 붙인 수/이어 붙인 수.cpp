#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string tmp1 = "";
    string tmp2 = "";
    
    for(int i=0; i<num_list.size(); i++){
        if (num_list[i]%2==0)
            tmp1 += to_string(num_list[i]);
        else
            tmp2 += to_string(num_list[i]);
    }
    
    return stoi(tmp1) + stoi(tmp2);
}