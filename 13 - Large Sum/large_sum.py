# Python 3.0's native handling of "bignums" makes this problem trivial...
# http://stackoverflow.com/questions/538551/

sum = 0
t = int(input())
while t:
    n = int(input())
    sum += n
    t -= 1

print((str(sum))[0:10])