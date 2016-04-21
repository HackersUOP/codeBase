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
Only works for small input
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;
int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}
int lcm(int a, int b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, l, h;
        cin >> n >> l >> h;
        vector<int> cont;
        for (int j = 0; j < n; j++) {
            int y;
            cin >> y;
            cont.push_back(y);
        }
        sort(cont.begin(), cont.end());
        bool can = false;
        for (int j = l; j <= h; j++) {
            bool yn = true;
            for (int k = 0; k < n; k++) {
                if (!((cont[k] % j == 0) || (j % cont[k] == 0))) {
                    yn = false;
                    break;
                }
            }
            if (yn) {
                printf("Case #%d: %d\n", i + 1, j);
                can = true;
                break;
            }
        }
        if (!can) printf("Case #%d: NO\n", i + 1);
    }
}
