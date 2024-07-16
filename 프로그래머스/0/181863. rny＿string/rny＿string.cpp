#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for (auto st : rny_string){
        if (st=='m') answer += "rn";
        else answer += st;
    }
    return answer;
}