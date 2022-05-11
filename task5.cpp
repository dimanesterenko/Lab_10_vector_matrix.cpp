//
// Created by Admin on 01.05.2022.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    int K = 4; //кількість рядків
    int P = 5; //кількість стовпців
    int r;
    srand(time(0));
    cout<< "Hello! For this task you should input P>=K!"<<endl;
    cout << "Input K:";
    cin >> K;
    cout << "Input P:";
    cin >> P;
    vector <int> goldiagonal(P), pobdiagonal(P);
    vector <vector<int> > matrix(K, vector<int>(P, 0));

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P; j++) {
            matrix[i][j] = 1 + rand() % 11;
            cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < P; j++) {
        for (int i = 0; i < K; i++) {
            goldiagonal[j] += matrix[i][(i + j) % P];
        }
    }

    for (int i = 0; i < goldiagonal.size(); i++) {
        cout << i << "->  " << goldiagonal[i] << endl;
    }
    cout << endl;

    for (int j = P-1; j >=0; j--) {
        pobdiagonal[j] = 1;
        for (int i = 0; i < K; i++) {
            pobdiagonal[j] *= matrix[i][(j-i+P) % P];
        }
    }
    for (int i = 0; i < pobdiagonal.size(); i++) {
        cout << i << "->  " << pobdiagonal[i] << endl;
    }
    cout << endl;
    return 0;
}
