#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, string> wordgame;
    
    for (int i=0; i<words.size()-1; i++){
        if (wordgame.find(words[i]) == wordgame.end()){
            if (words[i].back()==words[i+1].front())
                wordgame[words[i]] = words[i+1];
            else
                return vector<int>{(i+1)%n+1, (i+1)/n+1};
        }
        else
            return vector<int>{i%n+1, i/n+1};
        
    }
    int k = words.size()-1;
    if (wordgame.find(words[k])== wordgame.end())
        return vector<int>{0, 0};
    else 
        return vector<int>{k%n+1, k/n+1};
}