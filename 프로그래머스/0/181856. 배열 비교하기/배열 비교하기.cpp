#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if (arr1.size()!=arr2.size()) return (arr1.size()>arr2.size()) ? 1 : -1;
    else{
        int num1 = accumulate(arr1.begin(), arr1.end(), 0);
        int num2 = accumulate(arr2.begin(), arr2.end(), 0);
        if (num1==num2) return 0;
        else return (num1>num2) ? 1 : -1;
    }
}