#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int flag = arr.size()%2!=0 ? 0 : 1;
    for (int i=flag; i<arr.size(); i+=2){
        arr[i] += n;
    }
    return arr;
}