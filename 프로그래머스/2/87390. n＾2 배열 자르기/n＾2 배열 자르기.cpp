#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long k=left; k<=right; k++){
        int i = k/n;
        int j = k%n;
        if (i<j) answer.push_back(j+1);
        else answer.push_back(i+1);
    }
    
    return answer;
}