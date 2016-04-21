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
typedef long long ll;
typedef pair<int, int> pr;
string solve(char grid[][4], bool is_T, pr p, bool empty) {
    if (is_T) {
        int o = 0, x = 0;
        int j = p.first, k = p.second;
        for (int i = 0; i < 4; i++) {
            char c = grid[j][i];
            if (c == 'O') o++;
            if (c == 'X') x++;
            if (o == 3) return "O won";
            if (x == 3) return "X won";
        }
        o = 0, x = 0;
        for (int i = 0; i < 4; i++) {
            char c = grid[i][k];
            if (c == 'O') o++;
            if (c == 'X') x++;
            if (o == 3) return "O won";
            if (x == 3) return "X won";
        }
        if (j == k) {
            int o = 0, x = 0;
            for (int g = 0; g < 4; g++) {
                char c = grid[g][g];
                if (c == 'O') o++;
                if (c == 'X') x++;
                if (o == 3) return "O won";
                if (x == 3) return "X won";
            }
        }
        else if (j == (3 - k)) {
            int o = 0, x = 0;
            for (int g = 0; g < 4; g++) {
                char c = grid[g][3 - g];
                if (c == 'O') o++;
                if (c == 'X') x++;
                if (o == 3) return "O won";
                if (x == 3) return "X won";
            }
        }
    }
    int o = 0, x = 0;
    for (int i = 0; i < 4; i++) {
        o = 0, x = 0;
        for (int j = 0; j < 4; j++) {
            char c = grid[i][j];
            if (c == 'O') o++;
            if (c == 'X') x++;
            if (o == 4) return "O won";
            if (x == 4) return "X won";
        }
    }
    for (int i = 0; i < 4; i++) {
        o = 0, x = 0;
        for (int j = 0; j < 4; j++) {
            char c = grid[j][i];
            if (c == 'O') o++;
            if (c == 'X') x++;
            if (o == 4) return "O won";
            if (x == 4) return "X won";
        }
    }
    o = 0, x = 0;
    for (int g = 0; g < 4; g++) {
        char c = grid[g][g];
        if (c == 'O') o++;
        if (c == 'X') x++;
        if (o == 4) return "O won";
        if (x == 4) return "X won";
    }
    o = 0, x = 0;
    for (int g = 0; g < 4; g++) {
        char c = grid[g][3 - g];
        if (c == 'O') o++;
        if (c == 'X') x++;
        if (o == 4) return "O won";
        if (x == 4) return "X won";
    }
    if (empty) return "Game has not completed";
    else return "Draw";
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char grid[4][4];
        bool is_T = false;
        bool empty = false;
        pr p = make_pair(-1, -1);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                char c;
                cin >> c;
                if (c == 'T') {
                    is_T = true;
                    p = make_pair(j, k);
                }
                if (c == '.') empty = true;
                grid[j][k] = c;
            }
        }
        printf("Case #%d: %s\n", i + 1, solve(grid, is_T, p, empty).c_str());
    }
    return 0;
}
