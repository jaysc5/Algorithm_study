#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define INF 0x7fffffff

struct Package {
	int id; // 고유 식별자 ID
	int revenue; // 매출
	int dest; // 도착도시
	int profit; // 여행사가 벌어들이는 수익

	bool operator<(Package right)const {
		if (profit == right.profit) {
			return id > right.id;
		}
		return profit < right.profit;
	}
};

int N, M;
int arr[2000][2000];
int dist[2000];
bool isMade[30005];
bool isCancel[30005];
int startPoint;

priority_queue<Package, vector<Package>> pq;

void dijkstra() {
	bool visited[2000];
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		visited[i] = false;
	}

	dist[startPoint] = 0;

	for (int i = 0; i < N - 1; i++) {
		int v = 0, minDist = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && minDist > dist[j]) {
				v = j;
				minDist = dist[j];
			}
		}
		visited[v] = true;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[v] != INF && arr[v][j] != INF && dist[j] > dist[v] + arr[v][j]) {
				dist[j] = dist[v] + arr[v][j];
			}
		}
	}
}

// 랜드 건설
void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = INF;
		}
		// 출발지와 도착지가 같은 경우 거리는 0입니다
		arr[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int v, u, w;
		cin >> v >> u >> w;

		arr[v][u] = min(arr[v][u], w);
		arr[u][v] = min(arr[u][v], w);
	}
}


// 여행 상품 생성
void makeTour(int id, int revenue, int dest) {
	Package p;
	isMade[id] = true;
	p.id = id;
	p.revenue = revenue;
	p.dest = dest;
	p.profit = p.revenue - dist[p.dest];

	pq.push(p);
}

// 여행 상품 취소
void cancleTour() {
	int id;
	cin >> id;

	if (isMade[id]) isCancel[id] = true;
}

// 여행 상품 판매
void saleTour() {
	while (!pq.empty()) {
		Package p = pq.top();

		if (p.profit < 0) break;

		pq.pop();
		if (!isCancel[p.id]) {
			cout << p.id << "\n";
			return;
		}
	}
	cout << -1 << "\n";
	return;
}

// 출발지 변경
void changeDest() {
	cin >> startPoint;

	vector<Package> p;
	dijkstra();

	while (!pq.empty()) {
		p.push_back(pq.top());
		pq.pop();
	}

	for (Package pp : p) {
		makeTour(pp.id, pp.revenue, pp.dest);
	}
}



int main() {
	int Q;
	cin >> Q;

	while (Q--) {
		int querytype;
		cin >> querytype;

		if (querytype == 100) {
			input();
			dijkstra();
		}
		else if (querytype == 200) {
			int id, revenue, dest;
			cin >> id >> revenue >> dest;

			makeTour(id, revenue, dest);
		}
		else if (querytype == 300) {
			cancleTour();
		}
		else if (querytype == 400) {
			saleTour();
		}
		else if (querytype == 500) {
			changeDest();
		}

	}
	return 0;
}