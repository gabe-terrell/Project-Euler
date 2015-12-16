import sys

def isLow(n):
    return n >= ord('a') and n <= ord('z')

def isUpp(n):
    return n >= ord('A') and n <= ord('Z')

def isNum(n):
    return n >= ord('0') and n <= ord('9')

syms = {ord('('), ord(')'), ord(';'), ord(':'), ord(','), ord('.'), ord("'"), ord('?'), ord('-'), ord('!'), ord(" ")}
def isSym(n):
    return n in syms

def solveKey(codes):
    for key in range(ord('a'), ord('z') + 1):
        if allValidDecrypts(key, codes):
            return chr(key)
    return '?'
                
def allValidDecrypts(k, codes):
    for c in codes:
        decrypt = k ^ c
        if isLow(decrypt) or isUpp(decrypt) or isNum(decrypt) or isSym(decrypt):
            continue
        else:
            return False
    return True

# Only concerned with the list of codes
codes = False
for line in sys.stdin:
    if not codes:
        codes = True
    else:
        nums = line
        
nums = [int(n) for n in nums.split()]

k1 = []
k2 = []
k3 = []

k = 1
for n in nums:
    if k == 1:
        k1.append(n)
        k = 2
    elif k == 2:
        k2.append(n)
        k = 3
    else:
        k3.append(n)
        k = 1

# Hackerrank Solution
print(''.join([solveKey(k) for k in [k1, k2, k3]]))
# Euler solution
keys = ''.join([solveKey(k) for k in [k1, k2, k3]])
total = 0
for k in k1:
    total += ord(keys[0]) ^ k
for k in k2:
    total += ord(keys[1]) ^ k
for k in k3:
    total += ord(keys[2]) ^ k
print(total)
