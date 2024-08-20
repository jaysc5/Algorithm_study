#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string,bool> phoneBook;
    for(string pb : phone_book) phoneBook[pb] = true;
    
    for (string phone : phone_book){
        string tmp = "";
        for (char p : phone){
            tmp += p;
            if (phoneBook[tmp] and tmp != phone)
                return false;
        }
    }
    return true;
}