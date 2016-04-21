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
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void findPrimeFactors(ll n) {
    ll d = 2;
    while (n > 1) {
        while (n % d == 0L) {
            printf("%lld ", d);
            n /= d;
        }
        d = d + 1L;
        if (d * d > n) {
            if (n > 1L) {
                printf("%lld ", n);
            }
            break;
        }
    }
    printf("\n");
}
int main() {
    ll n;
    scanf("%lld", &n);
    findPrimeFactors(n);
}
