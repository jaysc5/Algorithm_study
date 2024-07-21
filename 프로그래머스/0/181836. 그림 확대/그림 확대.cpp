#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for (int i=0; i<picture.size(); i++){
        string tmp = "";
        for (int j=0; j<picture[0].size(); j++){
            for (int x=0; x<k; x++) tmp += picture[i][j];
        }
        for (int x=0; x<k; x++) answer.push_back(tmp);
    }
    return answer;
}