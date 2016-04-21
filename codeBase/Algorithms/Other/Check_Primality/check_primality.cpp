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
bool isPrime(ll p)
{
    if (p < 2) return false;
    for (ll i = 2; i * i <= p; i++)
        if (p % i == 0)
            return false;
    return true;
}
int main() {
    ll n;
    scanf("%lld", &n);
    if (isPrime(n)) printf("%lld is a prime!\n", n);
    else printf("%lld is not a prime!\n", n);
}
