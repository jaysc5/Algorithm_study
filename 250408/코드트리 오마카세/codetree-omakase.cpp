#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct CMD
{
    int idx;
    int t;
    int x;
    string name;
    int n;

    CMD(int IDX, int T, int X, string NAME, int N) :
        idx(IDX), t(T), x(X), name(NAME), n(N) {}
};

int L, Q;
vector<CMD> querySet;
unordered_map<string, int> positionPerson; // 사람 : 위치
unordered_map<string, int> countEat; // 사람 : 먹을 초밥
unordered_map<string, int> timePerson; // 사람 : 방문 시간

bool cmpquery(CMD a, CMD b) {
    if (a.t < b.t) return true;
    if (a.t > b.t) return false;

    if (a.idx < b.idx) return true;
    if (a.idx > b.idx) return false;

    return false;
}

void Input() {
    int count = Q;
    while (count--) {
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            int t, x;
            string name;
            cin >> t >> x >> name;
            querySet.push_back(CMD(cmd, t, x, name, 0));
        }
        else if (cmd == 200) {
            int t, x, n;
            string name;
            cin >> t >> x >> name >> n;
            querySet.push_back(CMD(cmd, t, x, name, n));
            positionPerson[name] = x;
            countEat[name] = n;
            timePerson[name] = t;
        }
        else if (cmd == 300) {
            int t;
            cin >> t;
            querySet.push_back(CMD(cmd, t, 0, "", 0));
        }
    }
}

void Solution1() {
    for (int q = 0;q < Q;q++) {
        CMD query = querySet[q];
        if (query.idx != 100) continue;

        int sumTime = 0;
        int nowPosition = query.x;
        if (query.t < timePerson[query.name]) { // 초밥이 먼저 들어옴
            int diff = timePerson[query.name] - query.t;
            nowPosition = (nowPosition + diff) % L;

            if (nowPosition <= positionPerson[query.name]) { // 위치가 초밥 < 사람
                sumTime = timePerson[query.name] + positionPerson[query.name] - nowPosition;
                querySet.push_back(CMD(query.idx + 1, sumTime, positionPerson[query.name], query.name, 0));
            }
            else { // 위치가 초밥 > 사람
                sumTime = timePerson[query.name] + L - nowPosition + positionPerson[query.name];
                querySet.push_back(CMD(query.idx + 1, sumTime, positionPerson[query.name], query.name, 0));
            }

        }
        else { // 초밥이 늦게 들어옴
            if (nowPosition <= positionPerson[query.name]) { // 위치가 초밥 < 사람
                sumTime = query.t + positionPerson[query.name] - nowPosition;
                querySet.push_back(CMD(query.idx + 1, sumTime, positionPerson[query.name], query.name, 0));
            }
            else { // 위치가 초밥 > 사람
                sumTime = query.t + L - nowPosition + positionPerson[query.name];
                querySet.push_back(CMD(query.idx + 1, sumTime, positionPerson[query.name], query.name, 0));
            }
        }
    }
}

void Solution2() {
    sort(querySet.begin(), querySet.end(), cmpquery);

    int resultPerson = 0, resultSushi = 0;
    for (CMD query : querySet) {
        if (query.idx == 100) {
            resultSushi++;
        }
        else if (query.idx == 101) {
            resultSushi--;
            countEat[query.name]--;
            if (countEat[query.name] == 0) resultPerson--;
        }
        else if (query.idx == 200) {
            resultPerson++;
        }
        else if (query.idx == 300) {
            cout << resultPerson << " " << resultSushi << "\n";
        }
    }
}

int main() {
    cin >> L >> Q;

    Input();
    Solution1();
    Solution2();

    return 0;
}
