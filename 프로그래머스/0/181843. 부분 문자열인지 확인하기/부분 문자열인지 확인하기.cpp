#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    if (my_string.size()<target.size()) return 0;
    else if (my_string.size() == target.size()) {
        if (my_string == target) return 1;
    }
    else {
        for(int i=0; i<=my_string.size()-target.size(); i++){
            if (my_string.substr(i,target.size()) == target)
                return 1;
        }
    }
    return 0;
}