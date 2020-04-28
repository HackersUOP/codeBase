'''
    Copyright (C) 2020, Sathira Silva.  
    
    Problem Statement: Given an array of integers and a target sum, determine the sum nearest to but not exceeding 
    the target that can be created. To create the sum, use any element of your array zero or more times.
    
    Approach: This's a variation of the 0-1 knapsack problem which can be solved easily using Dynamic Programming. Given the capacity of
    the knapsack, we have to pack items from the given list of items (and there're infinitely many items from each item)
    such that the total size doesn't exceed the capacity of the knapsack.
    
    (01). Subproblem: dp[capacity] for all 0 < capacity <= k
                      Maximum capacity that can be packed from the items such that the total capacity doesn't exceed i.
    (02). Guessing:   is item i included or not?
    (03). Recurrence: dp[capacity] = max(dp[capacity], items[i] + dp[capacity - items[i]])
    (04). Toplogical order: for capacity -> 0,...,k
                                for item -> 0,...,n - 1
    (05). Original problem: dp[k]
    
    Time Complexity: O(n(k + 1)) ~= O(mk) ; m <= n
'''

def unboundedKnapsack(k, items):
    # Since the same item can be repeatedly appear in the given list, extract only the unique items. This makes the algorithm 
    # more efficient.
    items = list(set(items))
    n = len(items)
    dp = [0] * (k + 1)
    for capacity in range(k + 1):
        for i in range(n):
            if items[i] <= capacity:
                dp[capacity] = max(dp[capacity], items[i] + dp[capacity - items[i]])
    return dp[k]
