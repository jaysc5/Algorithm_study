#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int s : scoville) pq.push(s);

    while (pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + 2*second);
        answer++;
        if (pq.size()==1 && pq.top() < K) return -1;
    }
    return answer;
}