# Returns 1 + 2 + ... + n
def triNum (n):
    return (n*(n+1))//2

# Algorithm: Let SoM == Sum of Multiples
# Ans = SoM of 3 + SoM of 5 - SoM of 15 (to eliminate repeats)
# SoM of 3 == 3 * triNum(n // 3)
# I discovered this equality with some test cases on paper
def solve():
    n = int(input()) - 1
    ans = (3 * triNum(n//3)) + (5 * triNum(n//5)) - (15 * triNum(n//15))
    print(ans)

t = int(input())
for i in range(0,t):
    solve()