#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    if (a%2!=0 & b%2!=0) return pow(a,2) + pow(b,2);
    else if (a%2==0 & b%2==0) return abs(a-b);
    else return 2*(a+b);
}