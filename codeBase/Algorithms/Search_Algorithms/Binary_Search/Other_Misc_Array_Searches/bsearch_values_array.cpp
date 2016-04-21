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
Using this code:
Before perfrming any of these binary searches, the array in question MUST be sorted. Otherwise the results will most probably be wrong.
*/
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int> vec{ -3, -1, 2, 4, 5, 6, 7};
//smallest index with value greater than or equal to value(returns vec_size if no such element found)
int lind(int v, int vec_size) {
    int l = 0, r = vec_size, x;
    while (l < r) {
        x = (l + r) / 2;
        if (vec[x] >= v) r = x;
        else l = x + 1;
    }
    return l;
}
//smallest index with value greater than value(returns vec_size if no such element found)
int llind(int v, int vec_size) {
    int l = 0, r = vec_size, x;
    while (l < r) {
        x = (l + r) / 2;
        if (vec[x] > v) r = x;
        else l = x + 1;
    }
    return l;
}
//largest index lesser than or equal to value(returns -1 if no such element found)
int hind(int v, int vec_size) {
    int l = 0, r = vec_size, x;
    while (l < r) {
        x = (l + r) / 2;
        if (vec[x] > v) r = x;
        else l = x + 1;
    }
    return l - 1;
}
//largest index with value lesser than value(returns -1 if no such element found)
int hhind(int v, int vec_size) {
    int l = 0, r = vec_size, x;
    while (l < r) {
        x = (l + r) / 2;
        if (vec[x] >= v) r = x;
        else l = x + 1;
    }
    return l - 1;
}
//index of a particular value(returns -1 if there's no such value)
int bin_search(int v, int vec_size) {
    int l = 0, r = vec_size - 1, x;
    while (l <= r) {
        x = (l + r) / 2;
        if (vec[x] == v) return x;
        else if (vec[x] < v) l = x + 1;
        else r = x - 1;
    }
    return -1;
}
//check whether value exists in array
int bin_search(int v, int vec_size) {
    int l = 0, r = vec_size - 1, x;
    while (l <= r) {
        x = (l + r) / 2;
        if (vec[x] == v) return x;
        else if (vec[x] < v) l = x + 1;
        else r = x - 1;
    }
    return -1;
}
int main() {
    cout << bin_search(5, 7) << endl;
    return 0;
}
