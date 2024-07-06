#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    int index = num_list.size()-1;
    if (num_list[index] > num_list[index-1])
        answer.push_back(num_list[index]-num_list[index-1]);
    else
        answer.push_back(num_list[index]*2);
    return answer;
}