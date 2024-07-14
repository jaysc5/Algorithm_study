#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    for (auto st: my_string){
        if (st == alp[0]) answer += toupper(st);
        else answer += st;
    }
    return answer;
}