#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    
    int score[N];
    for(int i=0; i<N; i++){
        cin >> score[i];
    }
    sort(score, score+N);
    
    cout << score[N/2];
    
    return 0;
}