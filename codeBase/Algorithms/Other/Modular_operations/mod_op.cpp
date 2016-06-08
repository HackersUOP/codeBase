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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;
map<pr, ll> mp;
ll mult(ll a, ll b) {
    return (a * b) % MOD;
}
ll power(ll a, ll b) {
    ll ret = 1L;
    for (ll k = 0; k < b; k++) ret = mult(ret, a);
    return ret;
}
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    }
}
