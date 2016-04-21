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
int main() {
    const double mx = 1e9, eps = 1e-5;
    double left = 0, right = mx, target = 1e5, x;
    while ((right - left) > eps) {
        x = (left + right) / 2;
        if (x - target >= eps) right = x;
        else left = x;
    }
    printf("Value of left is %lf which is equal to our initial target with an error of less than 10^-5.\n", left);
}
