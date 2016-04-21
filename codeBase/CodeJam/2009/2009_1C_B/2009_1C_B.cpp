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
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long double ld;
typedef long long ll;
bool exist(vector<char> chars, char c, int n) {
    int l = 0, r = n - 1, x;
    while (l <= r) {
        x = (l + r) / 2;
        if (chars[x] == c) return true;
        else if (chars[x] > c) r = x - 1;
        else l = x + 1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ld N = (ld) n;
        ld X = 0.0L, Y = 0.0L, Z = 0.0, VX = 0.0L, VY = 0.0L, VZ = 0.0L;
        for (int j = 0; j < n; j++) {
            ld x, y, z, vx, vy, vz;
            cin >> x >> y >> z >> vx >> vy >> vz;
//cout<<x<<y<<z<<vx<<vy<<vz<<endl;
            X += x;
            Y += y;
            Z += z;
            VX += vx;
            VY += vy;
            VZ += vz;
        }
        ld a, b, c;
        a = X * X + Y * Y + Z * Z;
        b = X * VX + Y * VY + Z * VZ;
        c = VX * VX + VY * VY + VZ * VZ;
//cout<<a<<" "<<b<<" "<<c<<endl;
        ld dmin, tmin;
        if (b > (0.0L) || c == 0.0L) {
            dmin = sqrt(a / (N * N));
            tmin = 0.0L;
        }
        else {
            tmin = (-1.0L) * b / c;
            dmin = sqrt((a - (b * b / c)) / (N * N));
//dmin=sqrt((a+2*b*tmin+c*tmin*tmin)/(N*N));
        }
        cout << fixed << "Case #" << (i + 1) << ": " << dmin << " " << abs(tmin) << endl;
    }
    return 0;
}
