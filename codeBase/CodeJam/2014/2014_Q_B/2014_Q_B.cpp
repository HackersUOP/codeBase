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
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
#include <string>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        double c, f, x;
        cin >> c >> f >> x;
        double curr = x / 2.0L;
        double last = 100000000.0L;
        int ind = 1;
        while (curr < last) {
            last = curr;
            curr = 0.0L;
            for (int y = 0; y < ind; y++) curr += c / (2.0L + y * f);
            curr += (x / (2.0L + ind * f));
            ind++;
        }
        printf("Case #%d: %.7f\n", i + 1, last);
    }
    return 0;
}
