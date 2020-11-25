// Example program
#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> m){
    for(int i = 0; i < 9 ; i++){
        if(i%3 == 0 && i > 1){
            cout << endl;
        }
        cout<< m[i/3][i%3] << ' ';
    }
    
    cout << endl;
}
void printMatrix(int array[][9], int numMatrix){
    for(int i = 0; i < 9 ; i++){
        if(i%3 == 0 && i > 1){
            cout << endl;
        }
        cout<< array[numMatrix][i] << ' ';
    }
    
    cout << endl;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    
    int magic_mat[8][9]= {
    {8, 1, 6, 3, 5, 7, 4, 9, 2},
    {6, 1, 8, 7, 5, 3, 2, 9, 4},
    {4, 9, 2, 3, 5, 7, 8, 1, 6},
    {2, 9, 4, 7, 5, 3, 6, 1, 8}, 
    {8, 3, 4, 1, 5, 9, 6, 7, 2}, 
    {4, 3, 8, 9, 5, 1, 2, 7, 6}, 
    {6, 7, 2, 1, 5, 9, 8, 3, 4}, 
    {2, 7, 6, 9, 5, 1, 4, 3, 8}
    };
    int temp = 0;
    int best = 1000;
    int bestMatrix = 0;
    for(int i = 0; i<8; i++){       
        temp =  abs( s[0][0]-magic_mat[i][0]) + 
                abs( s[0][1]-magic_mat[i][1]) + 
                abs( s[0][2]-magic_mat[i][2]) + 
                abs( s[1][0]-magic_mat[i][3]) + 
                abs( s[1][1]-magic_mat[i][4]) + 
                abs( s[1][2]-magic_mat[i][5]) +
                abs( s[2][0]-magic_mat[i][6]) + 
                abs( s[2][1]-magic_mat[i][7]) + 
                abs( s[2][2]-magic_mat[i][8]); 
        if(temp < best){
            best = temp;
            bestMatrix = i;
            }
    }
    cout << "\n\nBest Matrix 3x3\n";
    printMatrix(magic_mat,bestMatrix);
    return best;
}


int main()
{
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "\n\nOriginal Matrix 3x3\n";
    printMatrix(s);
    
    int result = formingMagicSquare(s);
    cout << "Replacement Cost: " << result << "\n";


    return 0;
}
