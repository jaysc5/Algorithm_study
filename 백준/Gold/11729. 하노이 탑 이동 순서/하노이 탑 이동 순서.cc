#include<iostream>

using namespace std;

void hanoi(int n, int start, int to, int end) {
	if (n == 0) {
		return;
	}

	hanoi(n - 1, start, end, to);
	cout << start << " " << end << "\n";
	hanoi(n - 1, to, start, end);
}

int main() {
	int n;
	cin >> n;

	cout << (1 << n) - 1 << "\n";
	hanoi(n, 1, 2, 3);

	return 0;
}