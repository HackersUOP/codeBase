# Name  - Thilakarathna W M D U
# Email - dtdinidu7@gmail.com
# Date  - 08/04/2020

tm = int(input()) # number of test cases

for t in range(1, tm+1):
    lis = [int(i) for i in list(input())] # taking the input as list

    strg = '('*lis[0] + str(lis[0]) # final string to be displayed
    prev = lis[0]                   # track the previs count

    for i in range(1, len(lis)): # loop through the list
        tmp = lis[i]-prev
        prev = lis[i]
        if (tmp >= 0):
            strg += '('*tmp
        else:
            strg += ')'*(-1*tmp)
        strg += str(lis[i])      # adding the changes to the final strings to be displayed
    strg += ')'*lis[-1]
    print("Case #{}: {}".format(t, strg)) # print the final output


