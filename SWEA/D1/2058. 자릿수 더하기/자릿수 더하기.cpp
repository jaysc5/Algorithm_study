#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        int sum=0;
        for(int i=0;i<4; i++) {
            sum += T % 10;
            T /= 10;
        }
        cout << sum << endl;
	}
	return 0;
}