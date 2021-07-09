/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Watson gives Sherlock an array of integers. His challenge is to find an element of the array such that the sum 
                        of all elements to the left is equal to the sum of all elements to the right. For instance, given the array 
                        arr = [5, 6, 8, 11], 8 is between two subarrays that sum to 11. If your starting array is [1], that element 
                        satisfies the rule as left and right sum to 0.
                        You will be given arrays of integers and must determine whether there is an element that meets the criterion.
                        
   Approach:  Search for a pivot element which satifies the above condition. Maintain a left sum and a right sum where left sum is
              initially 0 and right sum is the sum of the entire array except the first element. Then, iterate over the array starting
              from 1st element. Check whether the left and right sums are equal. If not, add the previous element to the left sum
              and deduct the current element from the right sum (In each iteration we assume the current element to be the pivot).
              
   Time Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, leftSum, rightSum;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        int arr[n];
        bool found = false;
        leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            rightSum += arr[i];
        }
        rightSum -= arr[0];
        for (int i = 1; i < n; i++) {
            if (leftSum == rightSum) {
                found = true;
                break;
            }
            leftSum += arr[i - 1];
            rightSum -= arr[i];
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}
