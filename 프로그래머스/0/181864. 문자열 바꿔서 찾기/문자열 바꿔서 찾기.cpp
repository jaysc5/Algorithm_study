#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    string answer = "";

    for(auto st: myString){
        if (st=='B') answer += 'A';
        else answer += 'B';
    }

    for(int i=0; i<myString.size()-pat.size()+1; i++){
        if (answer.substr(i, pat.size()) == pat)
            return 1;
    }
    return 0;
}