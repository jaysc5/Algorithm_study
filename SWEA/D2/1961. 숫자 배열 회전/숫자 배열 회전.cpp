#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        
        int map[7][7];
        for (int i=0; i<N; i++){
            for (int j=0;j<N;j++){
                cin >> map[i][j];
            }
        }
        
        cout << "#" << test_case << endl;
        
        for (int i=0;i<N;i++){
            // 90
            for (int j=0; j<N; j++)
                cout << map[N-j-1][i];
            cout << " ";
            
            // 180
            for (int j=0; j<N; j++)
                cout << map[N-i-1][N-j-1];
            cout << " ";
            
            // 270
            for (int j=0; j<N; j++)
                cout << map[j][N-1-i];
            cout << endl;
        }
	}
	return 0;
}