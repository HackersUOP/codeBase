/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
/*
DESCRIPTION:
The Sieve of Erastothenes is a prime number sieve that is one of the fastest prime number sieves. It can be used to find all primes upto a given positive integer.
TIME COMPLEXITY:
USING THIS CODE:
This program prints all the primes upto(and including, if n is prime) n when n is given as the input.
EXAMPLE INPUT:
138
EXAMPLE OUTPUT:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137
EXAMPLE PROBLEMS:
https://www.facebook.com/hackercup/problem/582396081891255/ (must be logged in to Facebook to view this)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1);
    for(int i=0;i<=n;i++) prime[i]=true;
    for (int p = 2; p*p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
int main() {
    int n=1000000;
    sieveOfEratosthenes(n);
    return 0;
}
