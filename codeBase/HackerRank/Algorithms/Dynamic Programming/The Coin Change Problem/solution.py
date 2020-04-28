'''
    Copyright (C) 2020, Sathira Silva
    
    Problem Statement: You are working at the cash counter at a fun-fair, and you have different types of coins available to you in 
    infinite quantities. The value of each coin is already given. Can you determine the number of ways of making change for a particular 
    number of units using the given types of coins?
    
    Approach: This another variant of 0-1 Knapsack problem. Given different types of coins in infinite amounts, we have to find how many 
    number of subsets of coins are there such that the sum of the values of the coins in the subset is equal to the given amount. This
    can be easily solved by Dynamic Programming.
    
    (01). Subproblem: dp[change]
                      Number of ways of making change for 'change' units.
    (02). Guessing:   Include the current coin or not?
    (03). Recurrence: dp[change] += dp[change - coin] for all changes that can be made upto n and values of the coins.
                      dp[change] is dp[change] + number of ways of making change when coin 'coin' is included(for change-coin units).
                      Base Case: dp[0] - Number of ways of making change for 0 units is 1 i.e. doing nothing.
    (04). Topological Order: for coins, the order doesn't matter. for change in coin,...,(n + 1)
    (05). Original Problem: dp[n]
                            Number of ways of making change for n units.
                            
    Time Complexity: Less than O(nm); m = number of different coin types
'''

def getWays(n, coins):
    dp = [0] * (n + 1)
    # Base Case: Number of ways of making change for 0 units is 1 i.e. doing nothing.
    dp[0] = 1
    for coin in coins:
        for change in range(coin, n + 1):
            dp[change] += dp[change - coin]
    return dp[n]
