/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/sad-meiers-trivilization
    
    Approach: An extremely easy problem using the Sprague-Grundy theorem for impartial games. Let g be the grundy function for the game and n be the current state of the game i.e.
              the current HP.
              g(0) = 0  (Because the grundy number of a zero game is 0 i.e. the first player loses)
              g(1) = mex{0} = 1  (the 1st player can shoot with a damage level of 1 and win)
              g(2) = mex{0, 1} = 2  (the 1st player can shoot with a damage level of 2 and win)
              ...
              g(26) = mex{0, 1, ..., 25} = 26 (the 1st player can shoot with a damage level of 26 and win)
              g(27) = mex{1, 2, ...., 26} = 0 (Because the maximum damage level the 1st player can do is 26)
              ... and so on
              Therefore, we can obtain a general formula for g(n) by observing the pattern:
              g(n) = n % 27
              So, if the initial HP is divisible by 27, the 1st player loses. Also, in order for first player to win he must always make the grundy number of the next state to 
              zero. Which implies the initial damage level should be the grundy number of the initial state (because x ^ x = 0).
              
    
    For more details about Sprague-Grundy theorem and it's applications:
    https://www.hackerrank.com/topics/game-theory-and-grundy-numbers
    https://cp-algorithms.com/game_theory/sprague-grundy-nim.html
    https://www.topcoder.com/community/competitive-programming/tutorials/algorithm-games/
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n % 27;
    return 0;
}
