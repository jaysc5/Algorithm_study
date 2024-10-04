#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> counter;
    for (int i=0; i<tangerine.size(); i++) {
        counter[tangerine[i]]++;
    }
    
    vector<int> sort_count;
    for (const auto &c : counter) {
        sort_count.push_back(c.second);
    }
    sort(sort_count.rbegin(), sort_count.rend());
    
    int num_type = 0;
    int sum = 0;
    
    for (int count : sort_count) {
        sum += count;
        num_type++;
        
        if (sum >= k) break;
    }
    
    return num_type;
}