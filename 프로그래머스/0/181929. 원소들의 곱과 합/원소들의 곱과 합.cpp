#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0, mult = 1;
    for (int num : num_list){
        mult *= num;
        sum += num;
    }
    
    return (sum*sum > mult);
}