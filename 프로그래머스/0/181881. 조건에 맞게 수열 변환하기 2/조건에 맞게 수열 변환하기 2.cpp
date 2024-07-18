#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> check = arr;
    while(1){
        for (auto &a : arr){
            if (a >= 50 & a%2 ==0) a = a/2;
            else if (a < 50 & a%2 != 0) a = (a*2+1);
        }
        if (check==arr) return answer;
        else check = arr;
        answer++;
    }
}