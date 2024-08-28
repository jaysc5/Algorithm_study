#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+1, 0);
    for (int l : lost) student[l] -= 1;
    for (int r : reserve) student[r] += 1;
    
    for (int i=1; i<=n; i++){
        if(student[i] == 1) {
            if(student[i-1] == -1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == -1) 
                student[i] = student[i+1] = 0;
        }

    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}