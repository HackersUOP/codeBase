/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/1000-shades-of-grey
  
  Approach: In simple terms the problem asks to find the maximum length subsequence of the indices of the array, when sorted, either all of the indices in the subsequence are
            strictly increasing or first decreasing then increasing (reverse bitonic). Because, the lower indices belong to the tiles which are firstly plastered onto the floor
            and the higher indices are the ones which are plastered later. Therefore, when sorted by the magnitude of the shade, always the indices increase right to left or 
            increase right to left ending at 0 and increase left to right starting from 0. So the goal is to find the longest length of the subsequence.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int m;
        cin >> m;
        vector<pair<int, int>> shades(m);
        for (int i = 0; i < m; i++) {
            cin >> shades[i].first;
            shades[i].second = i;
        }
        sort(shades.begin(), shades.end());
        // Calculate dp1[i] : longest strictly increasing subsequence ending at ith index
        int dp1[m], dp2[m], dp3[m];
        for (int i = 0; i < m; i++)
            dp1[i] = 1, dp2[i] = 1, dp3[i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++)
                if (shades[i].second > shades[j].second && dp1[i] < dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
        }
        // Calculate dp2[i] : longest strictly decreasing subsequence ending at ith index
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++)
                if (shades[i].second < shades[j].second && dp2[i] < dp2[j] + 1)
                    dp2[i] = dp2[j] + 1;
        }
        // Calculate dp3[i] : longest strictly decreasing subsequence ending at ith index from right to left
        for (int i = m - 2; i >= 0; i--) {
            for (int j = m - 1; j > i; j--)
                if (shades[i].second < shades[j].second && dp3[i] < dp3[j] + 1)
                    dp3[i] = dp3[j] + 1;
        }
        int M = dp2[0] + dp3[0] - 1;    // Longest length of the reverse bitonic subsequence
        for (int i = 1; i < m; i++)
            M = max(M, dp2[i] + dp3[i] - 1);
        cout << max(*max_element(dp1, dp1 + m), M) << endl;
    }
}
