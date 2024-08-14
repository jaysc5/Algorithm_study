#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(pair<int, float> &a, pair<int, float> &b){
    if (a.second == b.second) //실패율이 같다면
        return a.first < b.first; //작은 번호의 스테이지 먼저
    return a.second > b.second; //실패율이 높은 순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int people = stages.size(); //도전자
    vector<pair<int, float>> stagesPeople; //스테이지, 실패율
    
    for (int i=1; i<=N; i++){
        if (people==0){ //도전자가 없으면
            stagesPeople.push_back(pair<int, float>(i, 0));
            continue;
        }
        int cnt = count(stages.begin(), stages.end(), i); //스테이지에 도전 중인 사람
        float failratio = static_cast<float>(cnt)/ static_cast<float>(people); //float로 계산하기
        stagesPeople.push_back(pair<int, float>(i, failratio));
        people -= cnt; //남은 도전자 계산
    }
    
    sort(stagesPeople.begin(), stagesPeople.end(), compare);
    
    for (int i=0; i<N; i++){
        answer.push_back(stagesPeople[i].first);
    }
    return answer;
}