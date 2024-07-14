#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    int idx = myString.rfind(pat);
    return myString.substr(0, idx + pat.size());
}