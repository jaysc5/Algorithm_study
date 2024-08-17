#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> wordgame;
    
    wordgame.insert(words[0]);
    for (int i=1; i<words.size(); i++){
        if (!wordgame.insert(words[i]).second or words[i-1].back()!=words[i].front())
            return vector<int>{i%n+1, i/n+1};
    }
    return vector<int>{0, 0};
}