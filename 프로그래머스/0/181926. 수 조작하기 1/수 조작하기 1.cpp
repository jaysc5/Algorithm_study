#include <string>
#include <vector>
#include <map>

using namespace std;
map <char, int> m = {{'w', 1}, {'s', -1}, {'d', 10}, {'a', -10}};

int solution(int n, string control) {
    for (char c : control)
        n += m[c];
    return n;
}