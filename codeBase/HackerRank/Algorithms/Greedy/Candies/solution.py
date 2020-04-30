'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children 
                        sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants 
                        to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher 
                        rating must get more candies. Alice wants to minimize the total number of candies she must buy.
                        
    Approach:   Since each child must get at least one candy, give one candy per child initially. Then traverse the children starting from
                the 1st index and give them one more candy if that child's rating is higher than the previous child. Then traverse the
                children backwards starting from the child before the last index and compare the child's rating with the child sitting
                next to him. If that child's rating is higher than the child sitting next to him, make a greedy choice to give candies
                to him i.e. if the child has candies more than the next child, don't give any candies to him. Otherwise get all the candies
                he currently has and give him candies one more than the amount of the next child has.
'''

def candies(n, arr):
    candyCount = [1] * n
    for i in range(1, len(arr)):
        if arr[i] > arr[i - 1]:
            candyCount[i] = candyCount[i - 1] + 1
    for i in range(len(arr) - 2, -1, -1):
        if arr[i] > arr[i + 1]:
            candyCount[i] = max(candyCount[i], candyCount[i + 1] + 1)
    return sum(candyCount)
