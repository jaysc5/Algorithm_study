#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    for (string g : goal){
        if (!cards1.empty() and g == cards1[0])
            cards1.erase(cards1.begin());
        else if (!cards2.empty() and g == cards2[0])
            cards2.erase(cards2.begin());
        else
            return "No";
    }
    return "Yes";
}