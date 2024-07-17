#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for (auto itv : intervals)
        answer.insert(answer.end(), arr.begin()+itv[0], arr.begin()+itv[1]+1);
    return answer;
}