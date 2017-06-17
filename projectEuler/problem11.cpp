//
//  problem11.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//

#include <iostream>
#include <fstream>
using namespace std;



int main() {
    int MAXSIZE = 19;
    int map[20][20] = { {0} };
    ifstream file("problem11.txt");
    
    if (file.is_open() ) {
        char ch;
        int count = 0;
        int column = 0;
        int row = 0;
        while (file >> ch) {
            if (column == 20) {
                column = 0;
                row++;
            }
            if (count % 2 == 0) {
                map[row][column] = (ch - 48) * 10;
            }
            else {
                map[row][column] += ch - 48;
                column++;
            }
            count++;
        }
    
        
        file.close();
    }
    else {
        cout << "File not accessible" << endl;
    }
    
    long maxProduct = 0;
    long product;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            
        //Check Horizontal (Only To Right)
            product = 1;
            for (int column = j; column < j + 4; column++) {
                if (column > MAXSIZE) {
                    break;
                }
                product *= map[i][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
        //Check Vertical (Only Down)
            product = 1;
            for (int row = i; row < i + 4; row++) {
                if (row > MAXSIZE) {
                    break;
                }
                product *= map[row][j];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
        //Check Diagonal
            //(1)
            product = 1;
            for (int row = i, column = j; row < i + 4; row++, column++) {
                if (row > MAXSIZE || column > MAXSIZE) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
            //(2)
            product = 1;
            for (int row = i, column = j; row > i - 4; row--, column++) {
                if (row < 0 || column > MAXSIZE) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
            //(3)
            product = 1;
            for (int row = i, column = j; row < i + 4; row++, column--) {
                if (row > MAXSIZE || column < 0) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
        }
    }
    cout << "Answer: " << maxProduct << endl;
};