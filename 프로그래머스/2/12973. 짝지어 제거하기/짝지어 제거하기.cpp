#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stk;
    
    for (char st : s){
        if (stk.empty()) stk.push(st);
        else {
            if (stk.top() == st) stk.pop();
            else stk.push(st);
        }
    }

    return stk.empty();
}