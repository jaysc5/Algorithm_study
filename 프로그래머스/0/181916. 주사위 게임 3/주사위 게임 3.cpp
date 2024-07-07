#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> v = {a, b, c, d};
    
    sort(v.begin(), v.end());
    if(v[0] == v[3]) return 1111 * v[0];
    else if(v[0] == v[2]) return pow(10*v[0]+v[3],2);
    else if(v[1] == v[3]) return pow(10*v[1]+v[0],2);
    else if(v[0] == v[1]){
        if(v[2] == v[3]) return ((v[0]+v[2]) * abs(v[0]-v[2]));
        else return v[2]*v[3];
    }
    else if(v[1] == v[2]){
        return v[0]*v[3];
    }
    else if(v[2] == v[3]){
        return v[0]*v[1];
    }
    else return v[0];
}