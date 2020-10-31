/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/pokemon-go-3-1
  
  Approach: The problem can be modeled as a maximum-cardinality bipartite matching problem with minimum edge weights. i.e. we have to assign a pokemon trainer per each pokemon 
            such that the time to reach out a pokemon is minimum. A brute force solution would be to check all possible assignments which is of order O(TChooseP) where T is
            the number of trainers and P is the number of pokemons (Because there exists T choose P number of perfect matchings). But a minimum-cost bipartite matching
            problem can be converted into a continuous optimization (a linear program) problem which can be solved using linear programming. Such algorithm exists and it's
            called the 'Hungarian Algorithm'. The algorithm consumes O(P^2T) (O(PT) to process the matrix and O(P) to recalculate the potentials).
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        int P, T;
        cin >> P >> T;
        double time[P + 1][T + 1];  // Stores the costs of the matchings. 1st row and column is kept for the convenience.
        for (int i = 1; i <= P; i++)
            for (int j = 1; j <= T; j++)
                cin >> time[i][j];
        vector<double> u (P + 1), v (T + 1);  // Potentials such that u[i] + v[j] <= time[i][j] (i = 1...P, j = 1...T)
        // p[j] contains the matching: for each column j = 1...T it stores the index of the corresponding row (0 if nothing is selected. Thus it's a free vertex).
        // (p[0] is maintained to store the current row under consideration)
        // The vector way stores the information (the parent pointers) to reconstruct the augmenting path.
        vector<int> p (T + 1), way (T + 1);
        // Iterate through all left vertices (Pokemons)
        for (int i = 1; i <= P; i++) {
            p[0] = i;
            int j0 = 0;
            vector<double> minv (T + 1, INF);  // Used to recalculate the potentials
            vector<bool> used (T + 1, false);  // To mark whether a right vertex is used or not
            // Iterate until a free right vertex (A free trainer) is found
            while (p[j0] != 0) {
                used[j0] = true;  // Mark the vertex (trainer) as used
                int i0 = p[j0], j1;
                double delta = INF;
                for (int j = 1; j <= T; j++)
                    if (!used[j]) {
                        double cur = time[i0][j] - u[i0] - v[j];
                        if (cur < minv[j])
                            minv[j] = cur, way[j] = j0;
                        if (minv[j] < delta)
                            delta = minv[j], j1 = j;
                    }
                for (int j = 0; j <= T; j++)
                    if (used[j])
                        u[p[j]] += delta, v[j] -= delta;
                    else
                        minv[j] -= delta;
                j0 = j1;
            }
            
            while (j0) {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            }
        }
        // Restore the answer (for each trainer, find the index of the pokemon he has been assigned)
        vector<int> ans(P + 1);
        for (int j = 1; j <= T; j++)
            ans[p[j]] = j;
        double res = 0;
        for (int i = 1; i <= P; i++)
            res += time[i][ans[i]];
        cout << fixed << setprecision(2) << res / P << endl;
    }
    return 0;
}
