/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme3-0/challenges/triangles-6
  
  Apporach: There are 3 cases to form a right triangle OPQ where O is the origin:
              (1). Right angle at O
              (2). Right angle at P
              (3). Right angle at Q
            Therefore, the problem can be broken down into 3 parts. It is easy to see that the number of traingles for the 1st case is n * n. Because when the right angle is at
            O, P and Q must lie on the x and y axes. The 2nd and 3rd cases are symmetrical so we can treat them as one. Therefore, let's consider the 2nd case where the right
            angle is at P. Suppose P lies on x or y axis. Again since the y-coordinate of P has the degree of freedom to be on anywhere in (1, n) and the x-coordinate of Q can 
            be anywhere in (1, n), there are n * n such triangles. Thus, there are 2 * n * n total triangles whose right angle is at P or Q which one of the points lie on x or
            y axis. Therefore, there are 3 * n * n total number of triangles that we can find trivially.
            
            For the other triangles in case (2) and (3) (P or Q being a right angle and doesn't lie on x or y axes), we have to search for the number of triangles by varying one
            point (say P) on integer non-zero x-y plane. Suppose P has coordinates (x, y). The gradient of the vector OP is y / x. In order to have a right angle at P, the slope
            of the vector PQ must be -x / y. So, we can find for possible integer coordinate Q points along the PQ line when P is fixed until we hit the x axis or when the x
            coordinate of Q reach n. Therefore, to find the number of triangles we have to find how many integer steps we can come down along the vector PQ starting from P
            until we reach y = 0 or x = n. Let dx and dy be the lengths of corresponding x and y integer steps: dx = y / gcd(x, y), dy = x / gcd(x, y)
            Therefore, the number of triangles is the minimum of (n - x) / dx and y / dy
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 3 * n * n; // Trivially found solution
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++) {
            int g = __gcd(x, y);
            result += min(y * g / x, (n - x) * g / y) * 2;
        }
    cout << result;
    return 0;
}
