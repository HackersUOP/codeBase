/*
    Copyright (C) 2020, Sathira Silva.
    
    Approach: This is a pure model for a Markov Chain. The state space is S = {1, 2, ... , n}. The states of the markov chain can be modeled by Geometric random variables because
              each random variable has two outcomes: either success to the next square or failure to the 1st square. The ultimate goal is to find how many iterations are needed
              to get a transient state to the absorbing state, starting with the given initial state square 1. There are several ways of doing this. One can find the fundamental
              matrix and sum up the 1st row (and add 1: number of steps to getting into the first square) as explained in:
              https://en.wikipedia.org/wiki/Absorbing_Markov_chain#Expected_number_of_steps
              Another one may calculate the number of steps by finding a recurrence formula. But the easiest way is to start from the last state and going backwards untill the 
              first state. The probability of getting into the nth square from the (n - 1)th square p(n - 1). Thus, the expected value is 1 / p(n - 1) since the random variables
              are modeled by geometric distribution. Note that the expected value of getting into the nth square from (n - 1)th square is the number of steps it takes. The
              probability of getting into the nth square from the (n - 2)th square is p(n - 2) * p(n - 1). Thus, the expected value is 1 / [p(n - 2) * p(n - 1)]. Then, total number
              of steps it takes to reach square n from (n - 2)th square is 1 / p(n - 1) + 1 / [p(n - 2) * p(n - 1)]. Likewise, we can iterate upto the 1st square.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while ((cin >> n) && n) {
        double res = 1, exp = 1;
        double p[n - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> p[i];
        for (int i = n - 2; i >= 0; i--) {
            exp /= p[i];
            res += exp;
        }
        cout << (int) (res + 0.5) << endl;  // Round to the nearest integer
    }
}
