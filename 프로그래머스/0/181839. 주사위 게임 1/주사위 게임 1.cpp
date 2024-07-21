#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    if (a%2!=0 & b%2!=0) return a*a+b*b;
    else if (a%2==0 & b%2==0) return abs(a-b);
    else return 2*(a+b);
}