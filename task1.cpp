//
// Created by Admin on 01.05.2022.
//
#include<iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
    srand(time(0));
    int K, P;
    cout << "Enter K:";
    cin >> K;
    cout << "Enter P:";
    cin >> P;
    vector<vector<int>> matrix(K, vector<int>(P));
    cout << "MATRIX" << endl;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P; j++) {
            matrix[i][j] = 1 + rand() % 55 ;
            cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "___________________" << endl;
    int max = matrix[0][0];
    int row = 0, col = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                row = i;
            }
        }
    }
    int preMax=0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (preMax < matrix[i][j] && matrix[i][j]<max) {
                preMax = matrix[i][j];
                col = j;
            }
        }
    }
    //delete row with max
    matrix.erase(matrix.begin() + row);
    //delete column
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].erase(matrix[i].begin() + col);
    }
    cout<<"AFTER DELETING!\n";
    cout << "___________________" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout <<setw(2)<< matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}