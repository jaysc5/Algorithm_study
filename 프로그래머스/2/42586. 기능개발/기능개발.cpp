#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> q;

    for (int i=0; i<progresses.size(); i++){
        q.push_back(ceil((100.0-progresses[i])/speeds[i]));
    }
    
    int remain = q[0];
    int count = 0;

    for (int i=0; i<progresses.size(); i++){
        if (q[i] <= remain)
            count++;
        else{
            answer.push_back(count);
            remain = q[i];
            count = 1;
        }
    }
    answer.push_back(count);
    return answer;
}