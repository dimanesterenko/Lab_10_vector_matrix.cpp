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
    cout <<"MATRIX"<< endl;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P; j++) {
            cout << "\nInput matrix["<<i<<"]["<<j<<"] =  ";
            cin >> matrix[i][j];
        }
    }
    cout<<endl;
    //show matrix:)
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout<<"___________________"<<endl;
//odd or even rows
int index_odd=-1,index_even=-1;
    for (int i = 0; i < K; i++) {
        bool even = 1,odd = 1;
        for (int j = 0; j < P; j++) {
            if (matrix[i][j]%2 == 0) {
                odd = 0;
            }
            if (matrix[i][j] % 2 == 1) {
                even = 0;
            }
        }
        if (odd) {
            index_odd = i;
        }
        if (even) {
            index_even = i;
        }
    }
    cout<<"Index of odd row:"<<index_odd<<endl;
    cout<<"Index of even row:"<<index_even<<endl;

    // min, max - тесты успешны!
    int min = matrix[0][0], max = matrix[0][0];
    int index_min=0, index_max=0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                index_max = j;
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                index_min = j;
            }
        }
    }
    cout<<"Index column of max element: "<<index_max<<endl;
    cout<<"Index column of min element: "<<index_min<<endl;

    if (index_odd<0||index_even<0){
        cout<<"Please, input elements due to task"<<endl;
    }
    //change rows
    matrix[index_even].swap(matrix[index_odd]);
    //change columns
    for (int i=0; i < matrix.size(); i++)
        swap( matrix[i][index_max], matrix[i][index_min] );
    cout<<"___________________"<<endl;
    //show matrix after changing columns and rows
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

