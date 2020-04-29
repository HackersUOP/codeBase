/*
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  We define the following:
                           A subarray of array a of length n is a contiguous segment from a[i] through a[j] where 0 <= i <= j < n.
                           The sum of an array is the sum of its elements.
                        Given an n element array of integers, a, and an integer, m, determine the maximum value of the sum of any of its
                        subarrays modulo m.
                        
    Approach:  When dealing with subarray sums the most efficient way is to creating a prefix sum because it reduces time for repeating
               computations of subarray sums. Here the prefix modulo sum can be defined as: 
                        prefixSum(i) = (arr[0] + ... + arr[i]) % m
               Therefore, the subarray mod sum from a[i] to a[j] can be defined as:
                        subarraySum(i, j) = (prefixSum(j) - prefixSum(i - 1) + m) % m (m is added to handle the negative values)
               It can be seen that the subarray sum is maximum when prefixSum(i - 1) = prefixSum(j) + 1 because largest value the
               above expression can get is (m - 1). Therefore, we just need to find the indices i having the lowest prefix sum greater 
               than or equal to prefixSum(j) + 1 for each prefixSum(j). It's easier to use a Binary Search Tree consisting the prefix 
               sums to search those values efficiently.
               
    Total Time Complexity: O(nlog(n))
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, n;
    long long m;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> m;
        long long prefixSum = 0, maxSubarraySum = 0;
        set<long long> bbst; // Maintain a Balanced Binary Search Tree.
        bbst.insert(0);
        for (int i = 0; i < n; i++) {
            int current;
            cin >> current;
            prefixSum = (prefixSum + current % m) % m;
            maxSubarraySum = max(maxSubarraySum, prefixSum);
            // Find the lowest value in the prefix sum larger than or equal to one larger
            // than current prefix sum.
            auto iter = bbst.lower_bound(prefixSum + 1);
            if (iter != bbst.end())
                maxSubarraySum = max(maxSubarraySum, prefixSum - *iter + m);
            bbst.insert(prefixSum);
        }
        cout << maxSubarraySum << endl;
    }
    return 0;
}
