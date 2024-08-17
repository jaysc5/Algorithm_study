#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> ph;
    
    for (string p : participant){
        ph[p] += 1;
    }
    
    for (string c : completion){
        ph[c] -= 1;
        if (ph[c] == 0)
            ph.erase(ph.find(c));
    }
    
    return ph.begin()->first;
}