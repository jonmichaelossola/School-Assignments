//
//  main.cpp
//  InterviewPrep
//
//  Created by Jon Michael Ossola on 8/16/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    
    vector<int> scoreboard;
    int count = 1;
    
    scoreboard.resize(alice.size());
    
    //lets go about this differently
    for (int i = 0; i < scores.size(); i++)
    {
        // Increment count here
        if (i == 0) ;
        else if (scores[i] == scores[i-1]) ;
        else count++;
        
        for (int j = 0; j < alice.size(); j++)
        {
            if (i == scores.size()-1 && scoreboard[j] == 0) {
                scoreboard[j] = count+1;
            }
            else if (i == 0 && alice[j] >= scores[0]) {
                scoreboard[j] = count;
            }
            else if (alice[j] >= scores[i] && alice[j] < scores[i-1]) {
                scoreboard[j] = count;
            }
        }
    }
    return scoreboard;
}

int main(int argc, const char * argv[]) {
    vector<int> scores;
    scores.push_back(100);
    scores.push_back(100);
    scores.push_back(50);
    scores.push_back(40);
    scores.push_back(40);
    scores.push_back(20);
    scores.push_back(10);
    
    vector<int> alice;
    alice.push_back(5);
    alice.push_back(25);
    alice.push_back(50);
    alice.push_back(120);
    vector<int> scoreboard = climbingLeaderboard(scores, alice);
    
    cout << "{ ";
    for (int i = 0; i < scoreboard.size(); i++)
    {
        cout << scoreboard[i] << ' ';
    }
    cout << "}\n";
    return 0;
}
