'''
    Copyright (C) 2020, Sathira Silva.
    
    Problem Statement:  https://www.hackerrank.com/challenges/chief-hopper/problem
    
    Approach:   Since the bot must pass the last building with the lowest energy, traverse the bulidings backwards and find the the
                energy required using the given formula.
'''

from sys import stdin, stdout

def chiefHopper(buildings):
    minEnergy = 0
    for height in reversed(buildings):
        minEnergy = (1 + height + minEnergy) // 2
    return minEnergy

if __name__ == '__main__':
    n = int(stdin.readline())
    arr = list(map(int, stdin.readline().rstrip().split()))
    result = chiefHopper(arr)
    stdout.write(str(result) + '\n')
