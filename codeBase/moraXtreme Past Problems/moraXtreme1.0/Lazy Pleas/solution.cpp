/*
  Copyright (C) 2020, Sathira Silva.
  
  Link to the problem: https://www.hackerrank.com/contests/moraxtreme1/challenges/lazy-pleas
  
  Approach: Save the words in a map. For each plea, count the occurrences of the saved words in the plea and store the plea having the maximum so far count of words.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    map<string, int> words;
    for (int i = 0; i < a; i++) {
        string s;
        cin >> s;
        words[s] = 0;
    }
    int res = 0;
    string result;
    for (string s; getline(cin, s);) {
        stringstream ss(s);
        int temp = 0;
        string word;
        while (ss >> word)
            if (words.count(word) > 0)
                temp++;
        if (res < temp) {
            res = temp;
            result = s;
        }
    }
    cout << result << endl;
    return 0;
}
