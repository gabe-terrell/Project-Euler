# Returns two ints, p and r, s.t. p is prime and p * r == n
# Inspired from http://en.wikipedia.org/wiki/Primality_test
def prime_factor(n):
    if n % 2 == 0:
        return (2, n // 2)
    if n % 3 == 0:
        return (3, n // 3)
    for i in range(5, int(n ** 0.5) + 1, 6):
        if n % i == 0:
            return (i, n // i)
        if n % (i + 2) == 0:
            return (i + 2, n // (i + 2))
    return (n, 1)

# Repeatidly breaks up n into prime factors and keeps trak
# of which factor is the largest
def lpf (n):
    f = 1
    r = n
    while r != 1:
        p, r = prime_factor(r)
        if p > f:
            f = p
    print(f)
    
t = int(input())
for i in range(0,t):
    lpf(int(input()))
