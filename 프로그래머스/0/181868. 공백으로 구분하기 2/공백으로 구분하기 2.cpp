#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    stringstream ss(my_string);
    string buff;
    while (ss >> buff){
        answer.push_back(buff);
    }
    return answer;
}