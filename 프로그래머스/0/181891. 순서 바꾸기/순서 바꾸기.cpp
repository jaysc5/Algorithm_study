#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer = vector<int>(num_list.begin()+n, num_list.end());
    answer.insert(answer.end(), num_list.begin(), num_list.begin()+n);
    return answer;
}