#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Node {
public:
    int id;
    int weight;
private:
    Node* next;
    Node* prev;
    friend class DoubleLinkedList;
public:
    Node() {
        next = NULL;
        prev = NULL;
        id = 0;
        weight = 0;

    }
    Node(Node* n, Node* p, int i, int w) {
        next = n;
        prev = p;
        id = i;
        weight = w;
    }
    Node(int i, int w) {
        next = NULL;
        prev = NULL;
        id = i;
        weight = w;
    }
};

class DoubleLinkedList {
public:
    int size;

    explicit DoubleLinkedList(); // 생성자
    ~DoubleLinkedList(); // 소멸자
    void insertHead(int, int); // 헤드 삽입
    void insertTail(int, int); // 꼬리 삽입
    Node* deleteHead(); // 헤드 제거
    Node* deleteTail(); // 꼬리 제거
    Node* deleteSomewhere(Node *); // 어느 위치에서 제거
    void deleteSometoTail(Node*);
    Node* FindById(int);// id에 맞는 노드 찾기
    bool checkHead(int);
    void printAll();
private:
    Node* head;
    Node* tail;
protected:
    Node* remove(Node*);
    void add(Node*, int, int);
};

DoubleLinkedList::DoubleLinkedList() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
    size = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while (head->next != tail) {
        deleteHead();
    }
    delete head;
    delete tail;
}

void DoubleLinkedList::add(Node* v, int id, int weight) { //v 노드 추가
    Node* u = new Node(v, v->prev, id, weight);
    v->prev->next = u;
    v->prev = u;
}

void DoubleLinkedList::insertHead(int id, int weight) {
    add(head->next, id, weight);
    size++;
}

void DoubleLinkedList::insertTail(int id, int weight) {
    add(tail, id, weight);
    size++;
}

Node* DoubleLinkedList::remove(Node* v) { //v 노드 삭제
    Node* u = v->prev; //선행자
    Node* w = v->next; //후속자
    u->next = w;
    w->prev = u;

    return v;
}

Node* DoubleLinkedList::deleteHead() {
    Node *node = remove(head->next);
    size--;

    return node;
}

Node* DoubleLinkedList::deleteTail() {
    Node* node = remove(tail->prev);
    size--;

    return node;
}

Node* DoubleLinkedList::deleteSomewhere(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    size--;

    return node;
}

void DoubleLinkedList::deleteSometoTail(Node* node) {
    while (node->next != tail) {
        Node* remove = deleteTail();
        insertHead(remove->id, remove->weight);
    }
    Node* remove = deleteTail();
    insertHead(remove->id, remove->weight);
}

Node* DoubleLinkedList::FindById(int id) {
    Node* temp = head->next;
    while (temp != tail) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void DoubleLinkedList::printAll() {
    cout << "Head";
    Node* node = head->next;
    while (node != tail) {
        cout << " - (" << node->id << " : " << node->weight;
        node = node->next;
    }
    cout << " - Tail" << "\n";
}

bool DoubleLinkedList::checkHead(int w_max) {
    if (head->next->weight <= w_max) {
        return true;
    }
    else return false;
}

DoubleLinkedList giftBox[10];
bool isAvailable[10];
vector<pair<int, int>> gift;
int N, M;

void input(int N);

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int querytype;
        cin >> querytype;

        if (querytype == 100) {
            // 공장 설립
            cin >> N >> M;

            input(N);
            for (int m = 0; m < M; m++) {
                isAvailable[m] = true;
                for (int n = 0; n < N / M; n++) {
                    int id, weight;
                    tie(id, weight) = gift[(N / M) * m + n];
                    giftBox[m].insertTail(id, weight);
                }
            }
        }
        else if (querytype == 200) {
            int w_max;
            cin >> w_max;

            int downbox = 0;
            // 물건 하차
            for (int m = 0; m < M; m++) {
                if (isAvailable[m]) {
                    if (giftBox[m].checkHead(w_max)) {
                        // 맨 앞 하차
                        Node* down = giftBox[m].deleteHead();
                        // 하자 무게 더하기 + downbox
                        downbox += down->weight;
                        delete down;
                    }
                    else {
                        // 해당 선물 맨 뒤로 보내기
                        Node* down = giftBox[m].deleteHead();;
                        giftBox[m].insertTail(down->id, down->weight);
                        delete down;
                    }
                }
            }
            cout << downbox << "\n";
        }
        else if (querytype == 300) {
            int r_id;
            cin >> r_id;

            // 물건 제거
            bool flag = false;
            for (int m = 0; m < M; m++) {
                if (isAvailable[m]) {
                    Node* remove = giftBox[m].FindById(r_id);
                    if (remove != nullptr) {
                        Node* realmove = giftBox[m].deleteSomewhere(remove);
                        //giftBox[m].insertHead(realmove->id, realmove->weight);
                        delete realmove;
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) cout << r_id << "\n";
            else cout << -1 << "\n";
        }
        else if (querytype == 400) {
            int f_id;
            cin >> f_id;

            // 물건 확인
            bool flag = false;
            int m;
            for (m = 0; m < M; m++) {
                if (isAvailable[m]) {
                    Node* move = giftBox[m].FindById(f_id);
                    if (move != nullptr) {
                        giftBox[m].deleteSometoTail(move);
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) cout << m + 1 << "\n";
            else cout << -1 << "\n";

        }
        else if (querytype == 500) {
            int b_num;
            cin >> b_num;

            // 벨트 고장
            // 이미 망가져 있다면 -1
            // 아니면 b_num 출력

            b_num--;

            bool flag = true;
            if (isAvailable[b_num] == false) {
                flag = false;
            }
            else {
                isAvailable[b_num] = false;
                flag = true;
                for (int m = b_num; m < b_num + M; m++) {
                    m %= M;
                    if (isAvailable[m] == true) {
                        while (giftBox[b_num].size != 0) {
                            Node* down = giftBox[b_num].deleteHead();;
                            giftBox[m].insertTail(down->id, down->weight);
                        }
                        break;
                    }
                }
            }
            
            if (flag) cout << b_num + 1 << "\n";
            else cout << -1 << "\n";
        }

        //for (int m = 0; m < M; m++) {
        //    giftBox[m].printAll();
        //}
    }
    return 0;
}

void input(int N) {
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        gift.push_back({ tmp, 0 });
    }

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        gift[i].second = tmp;
    }
}