#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i++) {
        int check = 1;
        string tmp = "";
        for(int j = 0; j < babbling[i].size(); j++){
            if (tmp != "aya" and babbling[i].substr(j,3)=="aya") j += 2, tmp = "aya";
            else if (tmp != "ye" and babbling[i].substr(j,2)=="ye") j += 1, tmp = "ye";
            else if (tmp != "woo" and babbling[i].substr(j,3)=="woo") j += 2, tmp = "woo";
            else if (tmp != "ma" and babbling[i].substr(j,2)=="ma") j += 1, tmp = "ma";
            else {
                check = 0;
                tmp = "";
                break;
            }
        }
        if (check == 1) answer++;
    }
    return answer;
}