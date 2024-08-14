#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(pair<int, float> &a, pair<int, float> &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int people = stages.size();
    vector<pair<int, float>> stagesPeople;
    
    for (int i=1; i<=N; i++){
        if (people==0){
            stagesPeople.push_back(pair<int, float>(i, 0));
            continue;
        }
        int cnt = count(stages.begin(), stages.end(), i);
        float failratio = static_cast<float>(cnt)/ static_cast<float>(people);
        stagesPeople.push_back(pair<int, float>(i, failratio));
        people -= cnt;
    }
    
    sort(stagesPeople.begin(), stagesPeople.end(), compare);
    
    for (int i=0; i<N; i++){
        answer.push_back(stagesPeople[i].first);
    }
    return answer;
}