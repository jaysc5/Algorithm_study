#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];
    
    switch (n){
        case 1: return vector<int>(num_list.begin(), num_list.begin()+b+1);
        case 2: return vector<int>(num_list.begin()+a, num_list.end());
        case 3: return vector<int>(num_list.begin()+a, num_list.begin()+b+1);
        case 4:
            vector<int> answer;
            for(int i=a; i<=b; i+=c)
                answer.push_back(num_list[i]);
            return answer;
    }
}