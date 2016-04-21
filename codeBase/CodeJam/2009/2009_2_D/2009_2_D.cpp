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
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#include <sstream>
using namespace std;
typedef tuple<double, double, double> tp;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            double x, y, z;
            cin >> x >> y >> z;
            printf("Case #%d: %f\n", i + 1, z);
            continue;
        }
        if (n == 2) {
            double x, y, z;
            cin >> x >> y >> z;
            double x1, y1, z1;
            cin >> x1 >> y1 >> z1;
            printf("Case #%d: %f\n", i + 1, max(z, z1));
        }
        if (n == 3) {
            vector<tp> vec;
            for (int j = 0; j < 3; j++) {
                double x, y, z;
                cin >> x >> y >> z;
                vec.push_back(make_tuple(x, y, z));
            }
            float a = max((sqrt(pow((get<0>(vec[1]) - get<0>(vec[2])), 2.0) + pow((get<1>(vec[1]) - get<1>(vec[2])), 2.0)) + get<2>(vec[1]) + get<2>(vec[2])) / 2.0, get<2>(vec[0]));
            float b = max((sqrt(pow((get<0>(vec[0]) - get<0>(vec[2])), 2.0) + pow((get<1>(vec[0]) - get<1>(vec[2])), 2.0)) + get<2>(vec[0]) + get<2>(vec[2])) / 2.0, get<2>(vec[1]));
            float c = max((sqrt(pow((get<0>(vec[1]) - get<0>(vec[0])), 2.0) + pow((get<1>(vec[1]) - get<1>(vec[0])), 2.0)) + get<2>(vec[1]) + get<2>(vec[0])) / 2.0, get<2>(vec[2]));
            printf("Case #%d: %f\n", i + 1, min(min(a, b), c));
        }
    }
    return 0;
}
