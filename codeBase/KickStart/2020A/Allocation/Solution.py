'''
    Dinindu Udana
    dtdinidu7@gmail.com
    22/03/2020
'''

n = int(input())

for t in range(n):
    n, c = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]

    arr.sort() # sort the array
    count = 0
    cost = 0
    for i in arr:
        cost += i # add current value to count
        if cost <= c:
            count += 1 # count if cost is less than the given value
        else:
            break
    print("Case #{}: {}".format(t+1, count))
        