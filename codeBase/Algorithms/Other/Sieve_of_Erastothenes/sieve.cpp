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

void sieveOfEratosthenes(ll n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for (ll p=2; p<=n; p++){
		if (prime[p] == true){
			printf("%lld ",p);
			for (ll i=p*2; i<=n; i += p){
				prime[i] = false;
			}
		}		
	}
	printf("\n");
}

int main(){

    ll n;
    scanf("%lld",&n);
 	sieveOfEratosthenes(n);
	return 0;
}
