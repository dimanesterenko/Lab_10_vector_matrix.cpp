#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int main() {
      
	int N = 5; //кількість рядків
	int M = N; //кількість стовпців
	
	srand(time(0));
	
	vector <vector<int> > A(N, vector<int>(M, 0));
	cout <<"Утворена матриця"<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] =1+ rand() % 50;
			cout << setw(2) << A[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "___________________" << endl;
      cout <<"Головна діагональ"<< endl;

	for (int i = 0; i < N; i++) {
	cout << setw(2) << A[i][i] << "  " ;
	}
	cout << endl ;
	cout << "___________________" << endl;
      cout <<"Побічна діагональ"<< endl;

	for (int i = N-1; i >=0; i--) {
		cout << setw(2) << A[i][N - i - 1] << "  " ;
	}
	cout << endl;
	cout << "___________________" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i <= j) && (i <= N - 1 - j)) {
				A[i][j] = 0;
			}

			cout << setw(2) << A[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
} 
