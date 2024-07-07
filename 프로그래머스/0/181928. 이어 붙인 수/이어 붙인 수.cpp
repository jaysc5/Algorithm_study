#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string even = "", odd = "";
    
    for(int i=0; i<num_list.size(); i++)
        num_list[i]%2==0 ? even += to_string(num_list[i]) : odd += to_string(num_list[i]);
    
    return stoi(even) + stoi(odd);
}