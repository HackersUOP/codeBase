'''
    Copyright (C) 2020, Sathira Silva.
'''

from sys import stdin, stdout

if __name__ == '__main__':
    n = int(stdin.readline())
    prices = sorted(list(enumerate(map(int, stdin.readline().rstrip().split()))), key=lambda x: x[1])
    stdout.write(str(min(bought - sold for (yearBought, bought), (yearSold, sold) in zip(prices[1:], prices[:-1]) if yearSold > yearBought)))
