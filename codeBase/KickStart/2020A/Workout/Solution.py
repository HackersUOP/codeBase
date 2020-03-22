'''
    Dinindu Udana
    dtdinidu7@gmail.com
    22/03/2020
'''

n = int(input())
import heapq
import math

for t in range(n):
    tmp, k = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]
    count = [1]*(tmp-1) # array to hole the number of new items to be put between these elements
    diff = [0]*(tmp-1)  # array to hold the initiall differences
    Q = []

    for i in range(tmp-1):
        diff[i] = arr[i+1]-arr[i] # saving initial differences
        heapq.heappush(Q, (-diff[i], i)) # saving the current difference values
    #print(Q)

    for i in range(k): 
        val, ind = heapq.heappop(Q) # pop the max diff
        count[ind] += 1             # add new item between that pair to reduce the difference
        val = math.ceil(diff[ind]/count[ind]) # calculate the max difference
        heapq.heappush(Q, (-val, ind)) # push new diffrence to the heapq
        #print(Q)
    val, ind = heapq.heappop(Q) # pop the max difference
    print("Case #{}: {}".format(t+1, -val))

