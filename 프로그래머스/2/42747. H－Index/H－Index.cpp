#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for (int i=0; i<n; i++) {
        int hIndex = n-i;
        
        if (citations[i] >= hIndex) {
            answer = hIndex;
            break;
        }
    }
    return answer;
}