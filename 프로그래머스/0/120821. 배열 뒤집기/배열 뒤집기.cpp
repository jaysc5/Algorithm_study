#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num_list) {
    return vector<int>(num_list.rbegin(), num_list.rend());
}