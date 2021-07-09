/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  You and your friend decide to play a game using a stack consisting of N bricks. In this game, you can 
                        alternatively remove 1, 2 or 3 bricks from the top, and the numbers etched on the removed bricks are 
                        added to your score. You have to play so that you obtain the maximum possible score. It is given that your 
                        friend will also play optimally and you make the first move.
*/

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

vector<string> split_string(string);

long long bricksGame(vector<int> arr) {
    int n = arr.size();
    long long score[n];
    if (arr.size() <= 3)
        return accumulate(arr.begin(), arr.end(), 0);
    // Base Cases:
    score[n - 1] = arr[n - 1];
    score[n - 2] = score[n - 1] + arr[n - 2];
    score[n - 3] = score[n - 2] + arr[n - 3];
    long long sum = score[n - 3];
    // Build the optimal solution using the optimal solutions of it's subproblems.
    // Traverse the array backwards and get the cumulative sum at each state.
    for (int i = n - 4; i >= 0; i--) {
        sum += arr[i];
        score[i] = sum - min({score[i + 1], score[i + 2], score[i + 3]});
    }
    return score[0];
}
