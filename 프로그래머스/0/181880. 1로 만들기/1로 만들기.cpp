#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for (int &num : num_list){
        while (num!=1){
            if (num%2==0) num /= 2;
            else num = (num-1) / 2;
            answer++;
        }
    }
    return answer;
}