#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    for(auto st: myString){
        if (st=='a') answer += 'A';
        else answer += st;
    }
    return answer;
}