/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Palindromes are strings that read the same from the left or right, for example madam or 0110.
                        You will be given a string representation of a number and a maximum number of changes you can make. Alter the 
                        string, one digit at a time, to create the string representation of the largest number possible given the limit 
                        to the number of changes. The length of the string may not be altered, so you must consider 0's left of all 
                        higher digits in your tests. For example 0110 is valid, 0011 is not.
                        Given a string representing the starting number and a maximum number of changes allowed, create the largest 
                        palindromic string of digits possible or the string -1 if it's impossible to create a palindrome under the 
                        contstraints.
*/

#include <bits/stdc++.h>

using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    int changes = 0;
    bool change[n];
    // Traverse the string upto n / 2, front and end pair wise (s[i] and s[n - i - 1]).
    // First copy the large digit to the other in the pair if they're not equal and if there're more moves left.
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            change[i] = true;
            changes++;
            if (s[i] > s[n - i - 1])
                s[n - i - 1] = s[i];
            else
                s[i] = s[n - i - 1];
        }
        if (changes > k)
            return "-1";
    }
    // If there're more moves left, change the digits which are not 9 to 9.
    for (int i = 0; i < n / 2 && changes < k; i++) {
        if (s[i] != '9') {
            // We could have changed this digit to 9, therefore undo the previous change.
            if (change[i])
                changes--;
            if (changes < k - 1) {
                s[i] = s[n - i - 1] = '9';
                changes += 2;
            }
        }
    }
    // Finally handle the middle digit if the number of digits is odd.
    if (n % 2 && changes < k)
        s[n / 2] = '9';
    return s;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << highestValuePalindrome(s, n, k) << endl;
    return 0;
}
