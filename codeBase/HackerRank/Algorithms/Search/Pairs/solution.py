'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  You will be given an array of integers and a target value. Determine the number of pairs of array elements that 
                        have a difference equal to a target value.
                        
    Time Complexity: O(n) for both set conversion and set intersection operation.
'''

from sys import stdin, stdout

n, k = map(int, stdin.readline().rstrip().split())
arr = set(map(int, stdin.readline().rstrip().split()))
stdout.write(str(len(arr & set(d + k for d in arr))))
