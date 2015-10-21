# This algorithm works, but unfortunately times out due to Python runtimes
# Thus, I had to implement the exact same algorithm in C++ to pass the time check

# Keeping track of known primes
primes = [2, 3, 5, 7]

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

# Returns the sum of all primes not greater than n
def sumPrimes(n):
    sum = 0
    i = 0
    while primes[i] <= n:
        sum += primes[i]
        i += 1
    return sum

t = int(input())
i = 8
while t:
    n = int(input())
    while primes[-1] <= n:
        prime(i)
        i += 1
    print(sumPrimes(n))
    t -= 1