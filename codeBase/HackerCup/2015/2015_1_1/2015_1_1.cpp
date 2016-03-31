#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieveOfEratosthenes(ll n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for (ll p=2; p<=n; p++){
		if (prime[p] == true){
			printf("%d ",p);
			for (ll i=p*2; i<=n; i += p){
				prime[i] = false;
			}
		}		
	}
	printf("\n");
}

int main(){

    ll n;
    scanf("%lld\n",n);
 	sieveOfEratosthenes(n);
	return 0;
}
