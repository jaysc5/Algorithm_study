#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string buff;
    while (getline(ss, buff, ' ')){
        answer.push_back(buff);
    }
    return answer;
}