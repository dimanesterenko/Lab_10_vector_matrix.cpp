//
// Created by Admin on 01.05.2022.
//
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row;
    int col;
    bool isPositive = true;
    bool isNegative = true;
    int counter = 0;
    int additional = 1;
    cout << "Input rows ";
    cin >> row;
    cout << "Input cols ";
    cin >> col;
    vector<vector<int>>matrix(row, vector<int>(col));
    vector<int>rowPositive;
    vector<int>colNegative;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << "Input " << j + 1 << " element of " << i + 1 << " row" << endl;
            cin >> matrix[i][j];
        }}
    cout << "Initial array" << endl;
    for (int k = 0; k < matrix.size(); k++) {
        for (int l = 0; l < matrix[k].size(); l++) {
            cout << matrix[k][l] << " ";
        }
        cout << endl;}
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size() && isPositive; j++) {
            counter += 1;
            if (matrix[i][j] < 0) {
                isPositive = false;
            }
        }
        if (counter == col && isPositive) {
            rowPositive.push_back(i);
        }
        if (!isPositive) {
            isPositive = true;
        }
        counter = 0;}
    for (int k = 0; k < col; k++) {
        counter = 1;
        for (int l = 1; l < row; l++) {
            counter += 1;
            if (matrix[l][k] >= matrix[l-1][k]) {
                isNegative = false;
            }
        }
        if (counter == row && isNegative) {
            colNegative.push_back(k);
        }
        if (!isNegative) {
            isNegative = true;
        }
    }
    for (int i = 0; i < rowPositive.size(); i++) {
        matrix.insert(matrix.begin() + rowPositive[i] +additional, vector<int>(col, 0));
        additional+=1;
    }
    additional = 0;
    for (int i = 0; i < colNegative.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            matrix[j].insert(matrix[j].begin() + colNegative[i] + additional, 1);
        }
        additional += 1;
    }
    cout << "Edited array" << endl;
    for (int k = 0; k < matrix.size(); k++) {
        for (int l = 0; l < matrix[k].size(); l++) {
            cout <<" "<< matrix[k][l] << " ";
        }
        cout << endl;
    }
    return 0;
}