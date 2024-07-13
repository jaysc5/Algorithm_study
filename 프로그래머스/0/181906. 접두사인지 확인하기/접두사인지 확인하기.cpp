#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_prefix) {
    vector<string> v;
    for(int i=1; i<my_string.size(); i++)
        v.push_back(my_string.substr(0, i));
    if (find(v.begin(), v.end(), is_prefix) == v.end())
        return 0;
    return 1;
}