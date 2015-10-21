# Dictionary of collatz sequences
# Number maps to length of the chain
collatz = {1:1}

# Returns the next number in the collatz sequence
def iterate (n):
    if n % 2 == 0:
        return n // 2
    return 3 * n + 1

# Returns the length of the collatz sequence of n
# If not already computed, computes it and adds to the dictionary
def getCollatz (n):
    if n in collatz:
        return collatz[n]
    else:
        length = getCollatz(iterate(n)) + 1
        collatz[n] = length
        return length
    
t = int(input())
while t:
    n = int(input())
    longest = 1
    value = 1
    for i in range(1,n+1):
        if getCollatz(i) >= longest:
            longest = getCollatz(i)
            value = i
    print(value)
    t -= 1