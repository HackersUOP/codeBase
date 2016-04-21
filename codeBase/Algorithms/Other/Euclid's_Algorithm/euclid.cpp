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
DESCRIPTION:
The Euclid's Algorithm is one of the fastest algorithm's available to calculate the GCD of two numbers. If however the requirement is to calculate the GCD of a set of
numbers, we can easily extend the property that GCD(a,b,c)=GCD(a,GCD(b,c)) to determine the GCD of any number of numbers.
TIME COMPLEXITY:
USING THIS CODE:
This has two functions, gcd(a,b) and GCD(). gcd(a,b) is a utility function that calculates the GCD of two numbers(a and b) and GCD() uses gcd(a,b) pairwise on the numbers in the
vector vec to find the GCD of the whole set of numbers.
EXAMPLE INPUT:
5
32 56 40 28 100
EXAMPLE OUTPUT:
4
EXAMPLE PROBLEMS:
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int GCD() {
    int len = vec.size();
    if (len == 1) return vec[0];
    else {
        int val = gcd(vec[0], vec[1]);
        int ind = 2;
        while (ind < len) {
            val = gcd(val, vec[ind]);
            ind++;
        }
        return val;
    }
}
int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    printf("%d\n", GCD());
}
