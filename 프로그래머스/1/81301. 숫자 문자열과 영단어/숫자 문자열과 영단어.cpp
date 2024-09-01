#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string s) {
    vector<string> digit = {"0","1","2","3","4","5","6","7","8","9"};
    vector<string> word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    unordered_map<string, string> m;
    string st = "";
    string answer = "";
    for (int i=0; i<digit.size(); i++) m.insert({word[i], digit[i]});
    
    for (int i = 0; i < s.length();i++){
        st.push_back(s[i]);
        if (find(digit.begin(), digit.end(), st) != digit.end()) {
            answer += st;
            st="";
        } 
        
        if(m.find(st) != m.end()) {
            answer += m[st];
            st="";
        }
    }
    return stoi(answer);
}