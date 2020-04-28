  
'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement: In this challenge, you will be given an array B and must determine an array A. There is a special rule: For all i,
    A[i] <= B[i]. That is, A[i] can be any number you choose such that 1 <= A[i] <= B[i]. Your task is to select a series of A[i] given B[i]
    such that the sum of the absolute difference of consecutive pairs of A is maximized. This will be the array's cost, and will be 
    represented by the variable S below.
    
    S = Sum(|A[i] - A[i - 1]) from i = 2 to N
    
    Approach:  To obtain the maximum sum S, there're only two possibilities: A[i] is 1 or B[i]. We don't have to check any number between
    1 and B[i]. Therefore, this's sort of a 0-1 Knapsack problem. It can be solved by 4 lines of code using Dynamic Programming.
    
    (01). Subproblem:  Optimal sum of the absolute difference of consecutive pairs of prefix A[:i + 1].
                       max(dp)
                       Base Case: Initially, dp = [0, 0]. Because When A is empty, maximum sum is 0.
    (02). Guessing:    Is the maximum sum obtained when A[i] = 1 or A[i] = B[i]?
    (03). Recurrence:  dp = [max(dp[1] + B[i - 1] - 1, dp[0]), max(dp[1] + abs(B[i] - B[i - 1]), dp[0] + B[i] - 1)]
    (04). Topological Order: i from 1 to len(B) - 1
    (05). Original Probblem: max(dp) of A[:len(B)]
    
    Time Complexity:    O(|B| - 1)
'''

def cost(B):
    # Base Case
    dp = [0, 0]
    for i in range(1,len(B)):
        dp = [max(dp[1] + B[i - 1] - 1, dp[0]), max(dp[1] + abs(B[i] - B[i - 1]), dp[0] + B[i] - 1)]
    return max(dp)
