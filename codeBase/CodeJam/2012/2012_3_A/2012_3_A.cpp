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
#include <cfloat>
using namespace std;
typedef pair<int, double> pr;
bool pairCompare(const pr &one, const pr &two) {
    if (one.second == two.second) return one.first < two.first;
    return one.second < two.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pr> vec;
        vector<double> arr;
        for (int j = 0; j < n; j++) {
            double tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        for (int j = 0; j < n; j++) {
            double tmp;
            cin >> tmp;
            if (tmp == 0) vec.push_back(make_pair(j, DBL_MAX));
            else vec.push_back(make_pair(j, arr[j] / tmp));
        }
        sort(vec.begin(), vec.end(), pairCompare);
        cout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cout << vec[j].first << " ";
        }
        cout << endl;
    }
    return 0;
}
