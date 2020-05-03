/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Numeros the Artist had two lists that were permutations of one another. He was very proud. Unfortunately, while 
                        transporting them from one exhibition to another, some numbers were lost out of the first list. Can you find the 
                        missing numbers?
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ele;
    cin >> n;
    // Array to store frequencies of each missing element.
    int frequency[10001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> ele;
        // Decrement the frequencies of available elements so that the frequencies of the missing elements can be counted in the next step.
        frequency[ele]--;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ele;
        // Increment the frequencies of elements in the original array. This will cause the frequencies of the missing elements to
        // be greater than 0. Others will stay as 0.
        frequency[ele]++;
    }
    for (int i = 0; i < 10001; i++)
        if (frequency[i] > 0)
            cout << i << " ";
    cout << endl;
    return 0;
}
