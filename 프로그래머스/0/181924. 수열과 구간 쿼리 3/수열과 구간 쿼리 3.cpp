#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    int temp = 0;
    
    for(auto q : queries)
        swap(arr[q[0]], arr[q[1]]);

    return arr;
}