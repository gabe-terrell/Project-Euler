# Keeping track of known primes
primes = [2, 3, 5, 7, 11, 13]

# Check if n is prime. If it is, add to list
# Source: http://en.wikipedia.org/wiki/Primality_test
def prime(n):
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(n ** 0.5) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    primes.append(n)
    return True

t = int(input())
primesFound = 6
n = 17
while t:
    p = int(input())
    while primesFound < p:
        if prime(n):
            primesFound += 1
        n += 1
    print(primes[p-1])
    t -= 1