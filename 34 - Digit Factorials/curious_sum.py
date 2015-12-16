import sys

# Pre-processing factorials
fact = {0 : 1, 1 : 1, 2 : 2, 3: 6, 4 : 24, 5 : 120, 6 : 720, 7 : 5040, 8 : 40320, 9 : 362880}
# Pre-processing bounds from problem description
cSum = {10 : 0, 19: 19}

def isCurious (n):
    sum = 0
    num = n
    while num:
        digit = num % 10
        sum += fact[digit]
        num /= 10
    return sum % n == 0

# Good method for memoization... not needed for this problem however
def curiousSum (n):
    if n in cSum:
        return cSum[n]
    else:
        if isCurious(n):
            newSum = n + curiousSum(n - 1)
            cSum[n] = newSum
            return newSum
        else:
            newSum = curiousSum(n - 1)
            cSum[n] = newSum
            return newSum

# Simple Solution method
def curSum(n):
    sum = 0
    for i in range(10, n + 1):
        if isCurious(i):
            sum += i
    return sum

for n in sys.stdin:
    print(curSum(int(n)))