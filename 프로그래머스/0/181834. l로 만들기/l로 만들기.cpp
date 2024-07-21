#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (char s : myString){
        answer += ((s-'l') < 0) ? 'l' : s;
    }
    return answer;
}