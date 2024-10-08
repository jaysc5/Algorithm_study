#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stk;
    
    for (int i=0; i<prices.size(); i++){
        while (stk.size() != 0 and prices[i] < prices[stk.top()]){
            answer[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty()){
        answer[stk.top()] = prices.size() - stk.top() - 1;
        stk.pop();
    }
    return answer;
}