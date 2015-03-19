## Permutation game ## 

Source: https://www.hackerrank.com/challenges/permutation-game

### Problem Statement ###
Alice and Bob play the following game:
1. They choose a permutation of the first N numbers to begin with.
2. They play alternately and Alice plays first.
3. In a turn, they can remove any one remaining number from the permutation.
4. The game ends when the remaining numbers form an increasing sequence. The person who played the
last turn (after which the sequence becomes increasing) wins the game.

Assuming both play optimally, who wins the game?

### Input: ###
The first line contains the number of test cases T. T test cases follow. Each case contains an integer N on the
first line, followed by a permutation of the integers 1..N on the second line.
Output:
Output T lines, one for each test case, containing "Alice" if Alice wins the game and "Bob" otherwise.

Constraints:
1 <= T <= 100
2 <= N <= 15
The permutation will not be an increasing sequence initially.

Sample Input:
	2
	3
	1 3 2
	5
	5 3 2 1 4

Sample Output:
	Alice
	Bob

### Explanation: ###
For the first example, Alice can remove the 3 or the 2 to make the sequence increasing and wins the game. For the second example, if 4 is removed then the only way to have an increasing sequence is to only have 1 number left, which would take a total of 4 moves, thus allowing Bob to win. On the first move if Alice removes the 4, it will take 3 more moves to create an increasing sequence thus Bob wins. If Alice does not remove the 4, then Bob can remove it on his next turn since Alice can not win in one move.