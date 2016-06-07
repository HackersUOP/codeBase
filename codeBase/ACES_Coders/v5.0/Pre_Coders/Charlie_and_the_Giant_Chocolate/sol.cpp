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

#define MAX 41

using namespace std;

typedef long long ll;

ll C[MAX][MAX];

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (j == 0) C[i][j] = 1LL;
            else if (i == 0) C[i][j] = 0LL;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int a, b;
        cin >> a >> b;
        cout << C[a + b][b] << endl;
    }
    return 0;
}
