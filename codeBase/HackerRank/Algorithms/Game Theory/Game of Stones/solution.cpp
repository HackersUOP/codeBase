/*
    Copyright (C) 2020, Sathira Silva

    Link to the problem: https://www.hackerrank.com/challenges/game-of-stones-1/problem

    Approach:
        (1). Identify the winning and losing states of the game:
            This game differs from the 1 pile game because there are two losing states,
            namely n = 0 and n = 1 in this game.
        (2). Compute grundy numbers (or nimbers) for each state and try to come up with a general expression for nth state if possible:
            g(0) = 0    |
            g(1) = 0    | (Base Cases)
            g(2) = mex({0}) = 1     <- Player can remove 2 stones and go to state1
            g(3) = mex({0}) = 1     <- Player can either remove 2 or 3 stones and go to state1 or state0 respectively
            g(4) = mex({0, 1}) = 2  <- Player can either remove 2 or 3 stones and go to state2 or state1
            g(5) = mex({0, 1}) = 2  <- Player can remove 2, 3 or 5 stones and go to the states 3, 2 or 0 respectively
            g(6) = mex({0, 1, 2}) = 3
            g(7) = mex({1, 2}) = 0
            g(8) = mex({1, 2, 3}) = 0
            g(9) = mex({0, 2, 3}) = 1
            g(10) = mex({0, 2, 3}) = 1
            ... and so on

            It can be observed that the pattern continues in mod 7. Thus, if n mod 7 is not 0 or 1, the game state is winning.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << (n % 7 < 2 ? "Second" : "First") << endl;
    }
}
