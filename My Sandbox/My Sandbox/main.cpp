//
//  main.cpp
//  My Sandbox
//
//  Created by Jon Michael Ossola on 7/27/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void display(T matrix [4][4]) {
    
    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            if (k == 0)
                std::cout << std::endl;
            
            std::cout << matrix[i][k] << ' ';
        }
    }
}

void replace(int matrix [4][4], int depth, int length) {
    
    bool replace [4][4];
    std::cout << "Are we even getting here?\n";
    // now make the new matrice of bool flags
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < length; j++) {
            if (matrix[i][j] == 0)
                replace[i][j] = true;
            else
                replace[i][j] = false;
        }
    }
    
    // now swap the columns and rows for zeros. :D
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < length; j++) {
            if (replace[i][j]) {
                for (int s = 0; s < length; s++) {
                    matrix[i][s] = 0;
                }
                for (int k = 0; k < depth; k++) {
                    matrix[k][j] = 0;
                }
            }
        }
    }
    
    display(matrix);
}

int lengthOfLongestSubstring(string s) {
    
    vector<int> myTable(128);
    int highScore = 0;
    int current = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (!myTable[s[i]]) {
            myTable[s[i]] = s[i];
            current++;
            if (current > highScore)
                highScore = current;
        }
        else {
            current = 0;
            myTable.clear();
            myTable.resize(128);
            myTable[s[i]] = s[i];
            current++;
        }
    }
    
    return highScore;
}

int main()
{
    cout << lengthOfLongestSubstring("pwwkew");
    
    return 0;
}
