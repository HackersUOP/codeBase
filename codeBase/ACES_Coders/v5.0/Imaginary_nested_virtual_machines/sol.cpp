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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    ll T, T1, k;
    cin >> T >> T1 >> k;
    if (T1 <= 4 * k) {
        cout << "impossible" << endl;
        return 0;
    }
    ll l = 0;
    while (1) {
        ld t = T * pow(0.5L, l) + 4.0L * k * (1.0L - pow(0.5L, l));
        if ((T + 4 * k * ((1 << l) - 1)) <= T1 * (1 << l)) {
            printf("%lld %lld", l, T1 * (1 << l) - T - 4 * k * ((1 << l) - 1));
            return 0;
        }
        l += 1.0L;
    }
    return 0;
}
