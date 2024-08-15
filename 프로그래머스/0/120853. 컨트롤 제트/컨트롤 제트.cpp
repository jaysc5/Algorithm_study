#include <string>
#include <stack>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    istringstream ss(s);
    string buff;
    stack<int> stk;
    
    while (getline(ss, buff, ' '))
    {
        if (buff == "Z") stk.pop();
        else stk.push(stoi(buff));
    }

    while (!stk.empty()){
        answer += stk.top();
        stk.pop();
    }
    return answer;
}