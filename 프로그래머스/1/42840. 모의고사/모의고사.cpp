#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> mathcnt(3);
    vector<int> answer;
    
    for (int i=0; i<answers.size(); i++){
        if (answers[i] == first[i%first.size()])
            mathcnt[0]++;
        if (answers[i] == second[i%second.size()])
            mathcnt[1]++;
        if (answers[i] == third[i%third.size()])
            mathcnt[2]++;
    }
    
    int maxcount = *max_element(mathcnt.begin(), mathcnt.end());
    
    for (int i=0; i< mathcnt.size(); i++){
        if (maxcount == mathcnt[i])
            answer.push_back(i+1);
    }
    return answer;
}