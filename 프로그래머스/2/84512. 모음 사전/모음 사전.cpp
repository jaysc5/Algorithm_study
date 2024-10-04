#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt = 0;
string aeiou = "AEIOU";

void dfs(string word, string str) {
    char c[5] = {'A', 'E', 'I', 'O', 'U'};
    
    if (word == str) {
        answer = cnt;
        return;
    }
    
    for (int i=0; i<5; i++) {
        if (str.size()<5) {
            cnt++;
            dfs(word, str+c[i]);
        }
    }

}

int solution(string word) {
    dfs(word, "");
    return answer;
}