#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
  int A, B;
    cin >> A >> B;

    if (B-A==1 or B-A==-2){
        cout << "B" << endl;
    }
    else {
        cout << "A" << endl;
    }
	return 0;
}