#include <string>
#include <vector>

using namespace std;

int answer;
int tmp[2] = {-1, 1};

void dfs(vector<int> &numbers, int &target, int index, int result) {
    if (index >= numbers.size()) {
        if (result == target) answer++;
        return;
    }
    
    for (int i : tmp) {
        dfs(numbers, target, index+1, result+i*numbers[index]);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0 , 0);
    return answer;
}