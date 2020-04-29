/*
    Problem Statement:    https://www.hackerrank.com/challenges/red-john-is-back/problem
    
    Approach:   This problem can be solved using Dynamic Programming and Sieve of Eratosthenes (Or any other algorithm for sieving
    primes) easily. First we find the number of ways of covering a 4 x n wall with 4 x 1 and 1 x 4 bricks. Then we count the number of
    primes less than or equal to that number.
    
    (01). Subproblem:    dp[i]
                         (How many ways are there to cover a 4 x i wall)
    (02). Guess:         dp[i - 1] and dp[i - 4]
                         (Should we cover the remaining are with a 4 x 1 brick or a 1 x 4 brick?)
    (03). Recurrence:    dp[i] = dp[i - 1] + dp[i - 4]
                         (Base Cases: dp[0] = dp[1] = dp[2] = dp[3] = 1)
    (04). Toplogical Order:   i from  4 to n
    (05). Original Problem:   dp[n]
*/

#include <bits/stdc++.h>

using namespace std;

int dp[61];
bool prime[10000001];

void sieveOfEratosthenes(int n) 
{
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++) 
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false;
        } 
    }
} 

int redJohn(int n) {
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 4];
    int count = 0;
    for (int i = 2; i <= dp[n]; i++) {
        if (prime[i])
            count++;
    }
    return count;
}
