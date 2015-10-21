# A case study of the max and map functions

grid = []

# Finds best 4-num product in a single row
def maxrow (r):
    maxr = 0
    for c in range(0,16):
        prod = 1
        for i in range(0,4):
            prod *= grid[r][c+i]
        maxr = max(maxr, prod)
    return maxr

# Finds best 4-num product in a single column
def maxcol (c):
    maxc = 0
    for r in range(0, 16):
        prod = 1
        for i in range(0,4):
            prod *= grid[r+i][c]
        maxc = max(maxc, prod)
    return maxc

def maxdiag (r, c):
    rdiag = 1
    ldiag = 1
    for i in range(0,4):
        if r + i >= 20 or c + i >= 20:
            rdiag = 0
        else:
            rdiag *= grid[r+i][c+i]
        if r - i < 0 or c + i >= 20:
            ldiag = 0
        else:
            ldiag *= grid[r-i][c+i]
    return max(rdiag, ldiag)

def maxes():
    maxr = max(map(maxrow, range(0,20)))
    maxc = max(map(maxcol, range(0,20)))
    maxd = 0
    for i in range(0,20):
        maxd = max(maxd, max([maxdiag(i, j) for j in range(0,20)]))
    print(max(maxr, maxc, maxd))
    
for i in range(0,20):
    grid.append(list(map(int, input().split())))
maxes()