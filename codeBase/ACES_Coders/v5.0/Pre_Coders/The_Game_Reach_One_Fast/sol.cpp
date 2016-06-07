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

int A[501];

int solve(int a) {
  if (a == 1) return 0;
  if (a == 2 || a == 3) return 1;
  if (A[a] != -1) return A[a];
  else {
    int ret = 1 + solve(a - 1);
    if (a % 2 == 0 && a % 3 != 0) ret = min(ret, 1 + solve(a / 2));
    else if (a % 2 != 0 && a % 3 == 0) ret = min(ret, 1 + solve(a / 3));
    else if (a % 2 == 0 && a % 3 == 0) ret = min(ret, min(1 + solve(a / 2), 1 + solve(a / 3)));
    A[a] = ret;
    return ret;
  }
}

int main() {
  for (int i = 0; i < 501; i++) A[i] = -1;
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; t++) {
    int a, b;
    cin >> a >> b;
    int a1 = solve(a);
    int b1 = solve(b);
    cout << a1 << " " << b1 << endl;
    if (a1 > b1) cout << "BOB" << endl;
    else if (a1 < b1) cout << "ALICE" << endl;
    else cout << "DRAW" << endl;
  }
  return 0;
}
