def sumOfCubes(n):
    return ((n * (n + 1) // 2) % 10000000000 * (n * (n + 1) // 2) % 10000000000) % 10000000000

t = int(input())
for _ in range(t):
    n = int(input())
    res = 0
    for i in range(1, n + 1):
        d = n // i
        if d >= i:
            res += sumOfCubes(d)
        else:
            i -= 1
            lastd = n // i
            res += sum(((j ** 3) % 10000000000 * (n // j - i) % 10000000000) % 10000000000 for j in range(1, lastd))
            break
        res = res % 10000000000
    print(res % 1000000000)
