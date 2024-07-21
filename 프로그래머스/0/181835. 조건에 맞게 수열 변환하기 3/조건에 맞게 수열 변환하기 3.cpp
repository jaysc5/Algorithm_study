#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    bool odd = (k%2!=0) ? true : false;
    for (int i=0; i<arr.size(); i++){
        arr[i] = (odd) ? arr[i]*k : arr[i]+k;
    }
    return arr;
}