#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    if (num_list.size()>=11) return accumulate(num_list.begin(), num_list.end(), 0);
    else return accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>());
}