#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')
            answer.push_back((s[i]-'A' + n) % 26 + 'A');
        else if(s[i]>='a' && s[i]<='z')
            answer.push_back((s[i]-'a' + n) % 26 + 'a');
        else
            answer.push_back(s[i]);
    }
    return answer;
}