# Maps sequences of numbers to booleans
# True means that sequence is in increasing order
is_incr = {():True}

def isIncr (seq):
    if seq in is_incr:
        return is_incr[seq]
    else:
        if len(seq) < 2:
            is_incr[seq] = True
            return True
        elif isIncr(seq[:len(seq) - 1]):
            if seq[-2] < seq[-1]:
                is_incr[seq] = True
                return True
            else:
                is_incr[seq] = False
                return False

def bob (perm, pos):
    # take out number from Alice's move
    del perm[pos]
    
    # See if Alice has won
    if isIncr(tuple(perm)):
        return True
    
    # Try every permutation to see if Bob can win in this position
    for i in range(0,len(perm)):
        if not alice(perm[:],i):
            return False
        
    return True

def alice (perm, pos):
    # take out number from Bob's move
    if pos >= 0:
        del perm[pos]
    
    # See if Bob has won
    if isIncr(tuple(perm)):
        return False
    
    # Try every permutation to see if Alice can win in this position
    for i in range(0,len(perm)):
        if bob(perm[:],i):
            return True
        
    return False

def play():
    input()
    perm = list(map(int, input().split()))
    if alice(perm, -1):
        print("Alice")
    else:
        print("Bob")
    
    
tests = int(input())
for i in range(0,tests):
    play()