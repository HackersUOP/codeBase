/*
    Copyright (C) 2020, Sathira Silva.
    
    Link to the problem: https://www.hackerrank.com/contests/moraxtreme-4-0/challenges/tony-shark
    
    Approach: Sing 'Tony shark do-do-do-do-do-do/// Tony shark!' until you get a solution :)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3 || n > 12)
        cout << "invalid";
    else {
        string s = "";
        int tail = 0;
        int len = 6 * n + 2 * n * n;    // Length of the middle line
        // Print the top fin
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * n - i; j++)
                s += " ";
            for (int j = 0; j < 2 * i + 1; j++)
                s += "M";
            // Print the tail
            if (i != 0) {
                for (int j = 0; j <= len - n * n - 3 + n - 2 * i; j++)
                    s += " ";
                for (int j = 0; j < 1 + tail / 2; j++)
                    s += "M";
                tail++;
            }
            s += "\n";
        }
        // Print the top body
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (n - i) * (n - 2); j++)
                s += " ";
            for (int j = 0; j < 6 * n + 2 * n * i; j++)
                s += "M";
            for (int j = 0; j < 2 + 6 * n + 2 * n * (n - 1) + (n - 2) + (n - i - 1) - (n - i) * (n - 2) - (6 * n + 2 * n * i); j++)
                s += " ";
            for (int j = 0; j < 1 + tail / 2; j++)
                s += "M";
            tail++;
            s += "\n";
        }
        // Middle Line
        for (int j = 0; j < 6 * n + 2 * n * n; j++)
            s += "M";
        s += "\n";
        tail--;
        // Print the bottom body
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < (n - i) * (n - 2); j++)
                s += " ";
            for (int j = 0; j < 6 * n + 2 * n * i; j++)
                s += "M";
            for (int j = 0; j < 2 + 6 * n + 2 * n * (n - 1) + (n - 2) + (n - i - 1) - (n - i) * (n - 2) - (6 * n + 2 * n * i); j++)
                s += " ";
            for (int j = 0; j < 1 + tail / 2; j++)
                s += "M";
            tail--;
            s += "\n";
        }
        // Print the bottom fin
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n * n - i; j++)
                s += " ";
            for (int j = 0; j < 2 * i + 1; j++)
                s += "M";
            // Print the tail
            for (int j = 0; j < len - n * n - 3 + n - 2 * i; j++)
                s += " ";
            for (int j = 0; j < 1 + tail / 2; j++)
                s += "M";
            tail--;
            s += "\n";
        }
        cout << s;
    }
    return 0;
}
