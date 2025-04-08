#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
//#include <map>
//#include <set>

using namespace std;

struct SegmentTreeNode {
    int left = 0, right = 0, index = 0;
    int countData = 0;
    long long sumValue = 0;
};

int Q;
int entryCount;
unordered_map<string, int> name_to_index; // name : index
unordered_set<int> used_values; // value 사용 여부
//map<string, int> name_to_index; // name : index
//set<int> used_values; // value 사용 여부
string names[100005]; // 인덱스 : name
int values[100005]; // 인덱스 : value
vector<SegmentTreeNode> seg;

void update(int id, int left, int right, int node, int index, int count, int sum) {
    if (right < node || node < left) return;

    if (left == right) {
        seg[id].index = index;
        seg[id].countData = count;
        seg[id].sumValue = sum;
        return;
    }

    int mid = (left + right) / 2;
    
    if (node <= mid) {
        if (!seg[id].left) {
            seg[id].left = seg.size();
            SegmentTreeNode new_node;
            seg.push_back(new_node);
        }
        update(seg[id].left, left, mid, node, index, count, sum);
    }
    else {
        if (!seg[id].right) {
            seg[id].right = seg.size();
            SegmentTreeNode new_node;
            seg.push_back(new_node);
        }
        update(seg[id].right, mid + 1, right, node, index, count, sum);
    }

    seg[id].countData = seg[seg[id].left].countData + seg[seg[id].right].countData;
    seg[id].sumValue = seg[seg[id].left].sumValue + seg[seg[id].right].sumValue;
    return;
}

int query_rank(int node, int start, int end, int rank) {
    if (start == end) return seg[node].index;

    int mid = (start + end) / 2;

    if (seg[node].left) {
        if (seg[seg[node].left].countData >= rank) {
            return query_rank(seg[node].left, start, mid, rank);
        }
        else return query_rank(seg[node].right, mid + 1, end, rank - seg[seg[node].left].countData);
    }
    else {
        return query_rank(seg[node].right, mid + 1, end, rank);
    }

}

long long query_sum(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return seg[node].sumValue;

    int mid = (start + end) / 2;
    long long result = 0;

    if (seg[node].left) {
        result += query_sum(seg[node].left, start, mid, left, right);
    }

    if (seg[node].right) {
        result += query_sum(seg[node].right, mid + 1, end, left, right);
    }

    return result;
}

void handle_init() {
    seg.clear();
    SegmentTreeNode dummy;
    SegmentTreeNode root;
    seg.push_back(dummy);
    seg.push_back(root);

    entryCount = 0;
    name_to_index.clear();
    used_values.clear();
}

void handle_insert(string name, int value) {
    if (name_to_index.find(name) != name_to_index.end()) {
        cout << "0\n";
        return;
    }
    else if (used_values.find(value) != used_values.end()) {
        cout << "0\n";
        return;
    }
    
    entryCount++;
    name_to_index[name] = entryCount;
    used_values.insert(value);

    names[entryCount] = name;
    values[entryCount] = value;

    update(1, 1, 1e9, value, entryCount, 1, value);
    cout << "1\n";
}

void handle_delete(string name) {
    if (name_to_index.find(name) == name_to_index.end()) {
        cout << "0\n";
        return;
    }

    int idx = name_to_index[name];
    name_to_index.erase(name);
    used_values.erase(values[idx]);

    update(1, 1, 1e9, values[idx], idx, 0, 0);
    cout << values[idx] << "\n";
}

void handle_rank(int k) {
    if (seg[1].countData < k) {
        cout << "None\n";
        return;
    }
    int index = query_rank(1, 1, 1e9, k);
    cout << names[index] << "\n";
}

void handle_sum(int k) {
    long long sum_value = query_sum(1, 1, 1e9, 1, k);
    cout << sum_value << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Q;
    while (Q--) {
        string query_type;
        cin >> query_type;
        if (query_type == "init") {
            // 모든 데이터 삭제
            handle_init();
        }
        else if (query_type == "insert") {
            string name;
            int value;
            cin >> name >> value;
            // 데이터 삽입
            handle_insert(name, value);
        }
        else if (query_type == "delete") {
            string name;
            cin >> name;
            // 데이터 삭제
            handle_delete(name);
        }
        else if (query_type == "rank") {
            int k;
            cin >> k;
            // rank 출력
            handle_rank(k);
        }
        else if (query_type == "sum") {
            int k;
            cin >> k;
            // sum 출력
            handle_sum(k);
        }
    }

    return 0;
}
