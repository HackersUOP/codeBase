'''
    Problem Statement:  https://www.hackerrank.com/challenges/tower-breakers-revisited-1/problem
    
    Approach:   In this problem, Grundy Number for each pile is the number of prime factors with multiplicity included.
                More about Grundy Numbers:  https://www.hackerrank.com/topics/game-theory-and-grundy-numbers
                                            http://web.mit.edu/sp.268/www/nim.pdf
'''

#include <bits/stdc++.h>

using namespace std;

int primeFactors(int n) {
    int count = 0;
    while (n % 2 == 0) {
        n = n / 2;
        count += 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n = n / i;
            count += 1;
        }  
    }
    if (n > 2)  
        count += 1;
    return count;
}

int towerBreakers(vector<int> arr) {
    int grundy = 0;
    for (int i = 0; i < arr.size(); i++) {
        grundy ^= primeFactors(arr[i]);
    }
    return grundy? 1 : 2;
}
