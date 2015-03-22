def sumSquare (n):
    sum = 0
    for i in range(1,n+1):
        sum += i * i
    return sum

def squareSum (n):
    sum = 0
    for i in range(1,n+1):
        sum += i
    return sum * sum

def diff (n):
    return squareSum(n) - sumSquare(n)

t = int(input())
while t:
    n = int(input())
    print(diff(n))
    t -= 1