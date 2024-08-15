#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stk;
    
    for(int num : arr){
        if (stk.empty()) stk.push(num);
        else {
            if (stk.top() == num) continue;
            else stk.push(num);
        }
    }
    while (!stk.empty()){
        answer.push_back(stk.top());
        stk.pop();
    }
    return vector<int>(answer.rbegin(), answer.rend());
}