#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    int k = 10000;
    vector<pair<int, int>> attended;
    for(int i=0; i<rank.size(); i++){
        if (attendance[i]==true) attended.push_back({rank[i], i});
    }
    sort(attended.begin(), attended.end());
    return 10000 * attended[0].second + 100 * attended[1].second + attended[2].second;
}