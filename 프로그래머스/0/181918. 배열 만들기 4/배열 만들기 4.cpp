#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    while (i<arr.size()) {
        if (stk.empty()) stk.push_back(arr[i++]);
        else if (stk.back() < arr[i]) stk.push_back(arr[i++]);
        else stk.erase(stk.end()-1);
    }
    return stk;
}