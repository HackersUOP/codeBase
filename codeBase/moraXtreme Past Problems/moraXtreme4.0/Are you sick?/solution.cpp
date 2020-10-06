/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/are-you-sick/
    
    Apporach:   The problem is to find matches of given patterns in queried strings. String matching can be efficiently
                done using string hashing. Instead of comparing character by character, hashes for each patterns can be
                pre-calculated and compared with the hash value of the queried string. I've used the Rabin-Karp algorithm
                which uses that idea.
*/

#include <bits/stdc++.h>

using namespace std;

const int x = 123;  // Any random integer between 1 and p - 1

int main() {
    int g, t, p = 100007;   // Any large prime number
    cin >> g;
    vector<string> susPatterns(g);  // To store the susceptable patterns
    vector<int> susHashes(g, 0);    // To store the hash values of the patterns
    vector<int> h(g, 1);    // Used for rehashing (h[i] = x^(length of the pattern) % p for ith pattern)
    for (int i = 0; i < g; i++) {
        cin >> susPatterns[i];
        // Pre-calculate the hashes of patterns
        for (int j = 0; j < susPatterns[i].length(); j++)
            susHashes[i] = (x * susHashes[i] + susPatterns[i][j]) % p;
        // Pre-calculate the h-values for rehashing
        for (int j = 0; j < susPatterns[i].length() - 1; j++)
            h[i] = (h[i] * x) % p;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        string dna;
        cin >> dna;
        bool found = false;
        for (int j = 0; j < g; j++) {
            if (dna.length() < susPatterns[j].length())
                continue;
            int hash = 0;
            // Calculate the hash value of the string for the initial window
            for (int k = 0; k < susPatterns[j].length(); k++)
                hash = (x * hash + dna[k]) % p;
            for (int k = 0; k <= dna.length() - susPatterns[j].length(); k++) {
                // If hashes are equal, check whether the strings are actually equal. If not, it's a collision of hashes
                if (susHashes[j] == hash) {
                    int m;
                    for (m = 0; m < susPatterns[j].length(); m++)
                        if (dna[m + k] != susPatterns[j][m])
                            break;
                    if (m == susPatterns[j].length()) {
                        found = true;
                        break;
                    }
                }
                // Rehashing for the next window
                if (k < dna.length() - susPatterns[j].length()) {
                    hash = (x * (hash - dna[k] * h[j]) + dna[k + susPatterns[j].length()]) % p;
                    if (hash < 0)
                        hash += p;
                }
            }
            if (found)
                break;
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}
