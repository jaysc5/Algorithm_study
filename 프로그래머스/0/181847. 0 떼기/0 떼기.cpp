#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int idx = 0;
    for (char s : n_str) {
        if (s=='0') idx+=1;
        else break;
    }
    return n_str.substr(idx);
}