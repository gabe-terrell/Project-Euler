# x = number, k = number of consecutive digits, n = total digits
def largestProduct (x, k, n):
    max = 0
    for i in range(0, n-k+1):
        prod = 1
        for j in range(i,i+k):
            prod *= int(x[j])
        if prod > max:
            max = prod
    return max

t = int(input())
for i in range(0,t):
    nk = list(map(int, input().split()))
    n = nk[0]
    k = nk[1]
    print(largestProduct(input(), k, n))