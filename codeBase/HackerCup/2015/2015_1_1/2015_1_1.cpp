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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sieveOfEratosthenes(ll n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p <= n; p++) {
        if (prime[p] == true) {
            printf("%d ", p);
            for (ll i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    printf("\n");
}
int main() {
    ll n;
    scanf("%lld\n", n);
    sieveOfEratosthenes(n);
    return 0;
}
