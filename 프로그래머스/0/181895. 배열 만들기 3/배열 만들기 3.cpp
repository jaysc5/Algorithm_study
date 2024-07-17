#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> v0 = vector<int>(arr.begin()+intervals[0][0], arr.begin()+intervals[0][1]+1);
    vector<int> v1 = vector<int>(arr.begin()+intervals[1][0], arr.begin()+intervals[1][1]+1);
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}