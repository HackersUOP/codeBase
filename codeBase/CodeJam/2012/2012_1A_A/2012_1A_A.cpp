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
#include <stdio.h>
#include <float.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int A, B;
        cin >> A >> B;
        vector<double> probs, probs1;
        double ans = DBL_MAX;
        for (int j = 0; j < A; j++) {
            double db;
            cin >> db;
            probs.push_back(db);
        }
        double prod = 1.0;
        for (int a = 0; a < A; a++) {
            double temp;
            prod = prod * probs[a];
            probs1.push_back(prod);
            temp = probs1[a] * (B - A + 1 + 2 * (A - 1 - a)) + (1 - probs1[a]) * (2 * B - A + 2 * (A - 1 - a) + 2);
//cout<<temp<<endl;
            ans = (temp > ans) ? ans : temp;
        }
        double tmp = (double)(B + 2);
        ans = (tmp > ans) ? ans : tmp;
        printf("Case #%d: %f\n", i + 1, ans );
    }
}
