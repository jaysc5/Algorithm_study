#include<iostream>
using namespace std;

int main(void) {
	int f[100] = { 0 };
	f[0] = 0, f[1] = 1, f[2] = 1;

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 1];
	}

	cout << f[n] << ' ' << n - 2;

	return 0;
}
