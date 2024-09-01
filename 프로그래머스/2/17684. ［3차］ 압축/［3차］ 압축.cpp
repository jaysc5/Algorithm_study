#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;
    string s = "";
   
    for(int i = 1 ; i <= 26; i++){
        char c = 'A' + (i - 1);
        s ="";
        s += c;
        m.insert({s,i});
    }
   
    int idx = 27;
    s="";
    for(int i = 0; i < msg.length();i++){
        s.push_back(msg[i]);
        if(m.find(s) == m.end()){
            m.insert({s,idx});
            idx++;
            s.pop_back();
            answer.push_back(m[s]);
            s="";
            i--;
        }
    }
    answer.push_back(m[s]);
    return answer;
}