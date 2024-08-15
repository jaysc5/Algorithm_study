#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for (char c : s){
        if (stk.empty()){
            if (c == ')') return false;
            stk.push(c);
        }
        else {
            if (stk.top() == '(' and c == ')') stk.pop();
            else if (stk.top() == '(' and c == '(') stk.push(c);
            else return false;
        }
    }

    return stk.empty();
}