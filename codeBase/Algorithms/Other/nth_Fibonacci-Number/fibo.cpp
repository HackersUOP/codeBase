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
The Fibonacci Sequence is a sequence of positive integers with the property that each element is the sum of the previous two elements(the first two elements are both 1).
It is a standard exercise in dynamic programming and can be implemented in both the Top-Down and Bottom-Up approaches.
Both approaches have been implemented here.
TIME COMPLEXITY:
USING THIS CODE:
This program can output the nth Fibonacci Number given n as the input. The function fibo_td(n) calculates the ouptut using the Top-Down approach and the function fibo_bu(n)
implements it using the Bottom-Up approach.
EXAMPLE INPUT:
120
EXAMPLE OUTPUT:
4376692037216111008
4376692037216111008
EXAMPLE PROBLEMS:
*/
#include<bits/stdc++.h>
#define SIZE 1000000
using namespace std;
typedef unsigned long long ull;
ull mem_td[SIZE];
ull mem_bu[SIZE];
ull fibo_td(ull n) {
    if (n == 1 || n == 2) return 1;
    else if (mem_td[n] != 0) return mem_td[n];
    else {
        mem_td[n] = fibo_td(n - 1) + fibo_td(n - 2);
        return mem_td[n];
    }
}
ull fibo_bu(ull n) {
    for (int i = 3; i <= n; i++) mem_bu[i] = mem_bu[i - 1] + mem_bu[i - 2];
    return mem_bu[n];
}
int main() {
    memset(mem_td, 0, sizeof(ull)*SIZE);
    memset(mem_bu, 0, sizeof(ull)*SIZE);
    mem_td[1] = 1; mem_bu[1] = 1;
    mem_td[2] = 1; mem_bu[2] = 1;
    ull n;
    scanf("%llu", &n);
    printf("%llu\n", fibo_td(n));
    printf("%llu\n", fibo_bu(n));
}
