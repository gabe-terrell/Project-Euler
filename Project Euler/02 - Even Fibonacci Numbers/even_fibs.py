fib_dic = {0:1, 1:1}

def isEven (n):
    return (n % 2) == 0

def fib (n):
    if n in fib_dic:
        return fib_dic[n]
    else:
        f = fib(n - 1) + fib(n - 2)
        fib_dic[n] = f
        return f

def evenSum (n):
    sum = 0
    for i in range(1,n+1):
        f = fib(i)
        if f > n:
            break
        if isEven(f):
            sum += f
    print(sum)
    
t = int(input())
for i in range(0,t):
    n = int(input())
    evenSum(n)