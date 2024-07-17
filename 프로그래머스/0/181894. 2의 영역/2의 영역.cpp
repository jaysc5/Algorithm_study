#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++){
        if (arr[i]==2) answer.push_back(i);
    }
    if (answer.empty()) return {-1};
    else return vector<int>(arr.begin() + answer[0], arr.begin() + answer[answer.size()-1] +1);
}