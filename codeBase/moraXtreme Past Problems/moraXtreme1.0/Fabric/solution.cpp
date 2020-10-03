/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/fabric
  
  Approach: The naive brute force solution is to iterate through all possible squares and find the largest area rectangle which doesn't contain 1's. But if we can pre-calculate
            the number of 1's inside the rectangles, we only need to iterate over the four indices, say (i1, j1) and (i2, j2) where i1 <= i2 < h, j1 <= j2 < w. So the time
            complexity boils down from O(H^3W^3) to O(H^2W^2) because we can find rectangles without 1's in it in O(1) from the pre-calculated values. The pre-calculation can
            be done using dynamic programming as follows:
            (01). Subproblems:  The goal is to find the number of 1's inside the rectangle (i1, j1), (i2, j2) where i1 <= i2 < h, j1 <= j2 < w. But we can break this down to
                                a subproblem of finding the number of 1's inside the rectangle (0, 0), (i, j). i.e. dp[i + 1][j + 1].
                                Base Cases: dp[i][0] = 0, dp[0][j] = 0
                                
            (02). Recurrence:   dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + fabric[i - 1][j - 1] for H >= i >= 1, W >= j >= 1
            (03). Original Problem: Number of 1's inside the rectangle (i1, j1), (i2, j2) = dp[i2][j2] - dp[i1 - 1][j2] - dp[i2][j1 - 1] + dp[i1 - 1][j1 - 1]
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int h, w;
        cin >> h >> w;
        int fabric[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> fabric[i][j];
        int dp[h + 1][w + 1];   // dp[i + 1][j + 1] = number of 1's inside the rectangle starting at (0, 0) and ending at (i, j)
        for (int i = 0; i <= h; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= w; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + fabric[i - 1][j - 1];
        int area = 0;
        for (int i1 = 1; i1 <= h; i1++)
            for (int j1 = 1; j1 <= w; j1++)
                for (int i2 = i1; i2 <= h; i2++)
                    for (int j2 = j1; j2 <= w; j2++)
                        if (dp[i2][j2] - dp[i1 - 1][j2] - dp[i2][j1 - 1] + dp[i1 - 1][j1 - 1] == 0)
                            area = max(area, (i2 - i1 + 1) * (j2 - j1 + 1));
        cout << area << endl;
    }
}
