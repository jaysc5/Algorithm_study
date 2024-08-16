#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0 , idx2 = 0;
    
    for (string g : goal){
        if (!cards1.empty() and g == cards1[idx1])
            idx1++;
        else if (!cards2.empty() and g == cards2[idx2])
            idx2++;
        else
            return "No";
    }
    return "Yes";
}