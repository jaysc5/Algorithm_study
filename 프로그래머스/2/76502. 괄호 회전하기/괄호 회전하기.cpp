#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <map>

using namespace std;
map<char, char> bracket = {{'}','{'}, {')', '('}, {']', '['}};

int solution(string s) {
    int answer = 0;
    string ss = s + s;
    
    if (s.length()%2 != 0)
        return 0;
    
    for (int i=0; i<s.length(); i++){
        stack<char> stk;
        
        for (int j=i; j<i+s.length(); j++){
            if (ss[j]=='{' or ss[j]=='(' or ss[j]=='[' or stk.empty())
                stk.push(ss[j]);
            else{
                if (stk.top()=='}' or stk.top()==')' or stk.top()==']')
                    break;
                if (bracket[ss[j]] == stk.top())
                    stk.pop();
                else
                    stk.push(ss[j]);
            }
        }
        if(stk.empty()) answer += 1;
    }
    return answer;
}