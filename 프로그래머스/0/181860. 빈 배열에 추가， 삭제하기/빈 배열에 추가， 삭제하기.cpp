#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for(int i=0 ; i<arr.size() ; i++){
        if (flag[i]==true) 
            answer.insert(answer.end(), arr[i]+arr[i], arr[i]);
        else
            answer.erase(answer.end()-arr[i], answer.end());
    }
    return answer;
}