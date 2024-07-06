#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string sumab = to_string(a) + to_string(b);
    string sumba = to_string(b) + to_string(a);
    
    int sumAB = stoi(sumab);
    int sumBA = stoi(sumba);
    
    if (sumAB >= sumBA)
        return sumAB;
    else
        return sumBA;
}