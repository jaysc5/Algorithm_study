#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> charmap;
    
    for (char c : s){
        charmap[c] += 1;
    }
    
    for (auto it : charmap){
        if (it.second == 1)
            answer.push_back(it.first);
    }
    return answer;
}