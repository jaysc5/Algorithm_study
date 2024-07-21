#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (char s : myString){
        if ((s-'l') < 0) answer += 'l';
        else answer += s;
    }
    return answer;
}