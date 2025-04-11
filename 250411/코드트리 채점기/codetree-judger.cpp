#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct task
{
    int starttime;
    int p;
    string url;
    int domain;
    int domainID;

    bool operator<(const task& b) const {
        if (p != b.p) return p > b.p;
        if (starttime != b.starttime) return starttime > b.starttime;
        return false;
    }
};

int N; // 채점기 갯수
int nowtime;
task Judger[50001];
bool isused_judger[50001];

int domainCNT = 1;
unordered_map<string, int> domain_to_index;
string index_to_domain[301];

int startTime[301], gapTime[301];

priority_queue<task> waitingQ;
unordered_map<string, bool> iswaiting;

void init() {
    string u0;
    cin >> N >> u0;

    int idx = 0;
    for (int i = 0; i < u0.length(); i++) {
        if (u0[i] == '/') idx = i;
    }

    string domain = u0.substr(0, idx);
    int num = stoi(u0.substr(idx + 1));

    index_to_domain[domainCNT] = domain;
    domain_to_index[domain] = domainCNT;

    waitingQ.push({ nowtime, 1, u0, domain_to_index[domain], num });
    iswaiting[u0] = true;
}

void request() {
    int nowtimet, p;
    string u;
    cin >> nowtime >> p >> u;

    int idx = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '/') idx = i;
    }

    string domain = u.substr(0, idx);
    int num = stoi(u.substr(idx + 1));

    if (!domain_to_index[domain]) {
        domainCNT++;
        domain_to_index[domain] = domainCNT;
        index_to_domain[domainCNT] = domain;
    }
    
    if (!iswaiting[u]) {
        waitingQ.push({ nowtime, p, u, domain_to_index[domain], num });
        iswaiting[u] = true;
    }
}

void juding() {
    int nowtime;
    cin >> nowtime;

    if (waitingQ.empty()) return;

    task nowTask = waitingQ.top();
    // 도메인이 채점을 진행 중 불가
    // t < start + 3*gap 불가
    int idx = nowTask.domain;
    int cmptime = startTime[idx] + 3 * gapTime[idx];

    if (isused_judger[idx]) return;
    if (nowtime < cmptime) return;

    bool check = false;
    for (int i = 0; i < N; i++) {
        if (!isused_judger[i]) {
            isused_judger[i] = true;
            nowTask.starttime = nowtime;
            Judger[i] = nowTask;
            startTime[idx] = nowtime;
            check = true;
            break;
        }
    }

    if (check) {
        waitingQ.pop();
        iswaiting[nowTask.url] = false;
    }
}

void endJuding() {
    int jid;
    cin >> nowtime >> jid;

    jid--;
    if (isused_judger[jid]) {
        isused_judger[jid] = false;

        task endTask = Judger[jid];
        int idx = endTask.domain;
        gapTime[idx] = nowtime - startTime[idx];
        Judger[jid] = { 0,0,"" };
    }
}

void checkQueue() {
    cin >> nowtime;

    cout << waitingQ.size() << "\n";
}

int main() {
    int Q;
    cin >> Q;

    nowtime = 0;
    while (Q--) {
        int querytype;
        cin >> querytype;

        if (querytype == 100) {
            init();
        }
        else if (querytype == 200) {
            request();
        }
        else if (querytype == 300) {
            juding();
        }
        else if (querytype == 400) {
            endJuding();
        }
        else if (querytype == 500) {
            checkQueue();
        }
    }

    return 0;
}