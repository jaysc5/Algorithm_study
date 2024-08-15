#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for (char c : s){
        if (n < 0)
            return false;
        if (c == '(')
            n++;
        else if (c == ')')
            n--;
    }
    return n == 0;
}