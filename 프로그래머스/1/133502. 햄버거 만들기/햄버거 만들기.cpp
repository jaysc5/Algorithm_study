#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> s = {0};
    
    for (int i : ingredient){
        if (s.back()==1 and i==2) s.back() = 12;
        else if (s.back()==12 and i==3) s.back() = 123;
        else if (s.back()==123 and i==1) s.pop_back(), answer++;
        else s.push_back(i);
    }
    return answer;
}