## CSES Problem Set - Introductory Problems

### 1068 Weird Algorithm

Simulation of the sequence generation based on the rules:
Simple iterative algorithm to generate the sequence based on the rules provided. The algorithm continues until it reaches 1.

### 1083 Missing Number

Mathematical approach
To find the missing number in a sequence from 1 to n, calculate the expected sum of the first n natural numbers using the formula:

### 1069 Repetitions

Using 2 pointers, iterate through the string to find the longest consecutive repetition of a character. Keep track of the current character and its count, updating the maximum count when a different character is encountered.

### 1094 Increasing Array

Greedy approach.
To make the array non-decreasing, iterate through the array and compare each element with the previous one. If the current element is less than the previous one, increment it to match the previous element and add the difference to a total cost variable.

### 1070 Permutations

Think the even and odd numbers separately and append them to the result.
Check special cases for n = 1, 2, and 3:
For n > 3, append odd numbers first followed by even numbers.

### 1071 Number Spiral

### 1072 Two Knights

This is a counting problem.
Total ways to place 2 knights on a k×k board = C(k², 2) = k²(k²-1)/2
Minus the cases where they attack each other:

Each knight will have up to 2 potential attacking pairs per board configuration due to symmetry (if not near the edges).
The number of 2-knight attacking configurations on a ( k x k ) board is ( 4(k-1)(k-2) ),
derived as follows:
For each ( 2 x 3 ) or ( 3 x 2 ) area within the board, there are 2 positions where the knights attack each other.
There are ((k-1) x (k-2)) such ( 2 x 3 ) rectangles that fit horizontally and ((k-2) x (k-1)) vertically.

### 1092 Two Sets

This problem can be solved using a greedy approach
To divide the numbers from 1 to n into two sets with equal sum, we can use the following approach:

1. Calculate the total sum of numbers from 1 to n using the formula:  
   $$\text{total_sum} = \frac{n(n + 1)}{2}$$
2. If the total sum is odd, it's impossible to divide into two equal sets, so return "NO".
3. If the total sum is even, we can use a greedy approach to fill two sets:
   - Start from n and add numbers to the first set until the sum reaches half of the total sum.
   - The remaining numbers will automatically go into the second set.
   -

### 1617 Bit Strings

Compute 2^n % (10^9 + 7) using fast exponentiation.

### 1618 Trailing Zeros

calculates the number of factors 5 in n! by dividing n by 5,5^2,5^3 etc.

### 1754 Coin Piles

The total number of coins shall be divisible by 3,
Each move removes at least one coin from each pile, so the number of coins in a pile must be at most twice the number of coins in the other pile.
Use the greedy approach that remove 2 from the pile with the most coins and 1 from the other pile until one of the piles is empty.

### 1755 Palindrome Reorder

To check if a string can be rearranged into a palindrome, count the frequency of each character.
If at most one character has an odd frequency, it can be rearranged into a palindrome.
One way to rearrange is to place the odd character in the middle and the rest symmetrically around it.
From the frequency count, construct the first half of the palindrome and mirror it for the second half.

### 2205 Gray code

Build the Gray code sequence recursively, supposing we have the sequence for n-1 bits, we can generate the n-bit sequence by:

1. Taking the n-1 bit sequence and prefixing it with 0.
2. Taking the n-1 bit sequence in reverse order and prefixing it with 1.

### 2165 Tower of Hanoi

3 towers, n disks, and the goal is to move all disks from source to destination using an auxiliary tower.

### 1622 Creating Strings

Sort the input, using next_permutation to generate all permutations of the string,

### 1623 Apple Division

for n <= 20, use bitmasking to generate all subsets of apples and check if the sum of each subset is equal to half of the total sum.

### 1624 Checssboard and Queens

Regular 8-queens problem, where the goal is to place 8 queens on an 8x8 chessboard such that no two queens threaten each other.

Check each row, column, and diagonal for conflicts. Use backtracking to place queens one by one,

**_Primary Diagonal (Top-left to bottom-right diagonal):_**

All cells on this diagonal satisfy i - j = row - col.
To find j for a given i: j = col - (row - i)

**_Secondary Diagonal(Top-right to bottom-left diagonal):_**

All cells on this diagonal satisfy i + j = row + col.
To find j for a given i: j = col + (row - i)

### 3399 Raab Game I

One possbile player 1 plays '1,2,3,4,....,n',
player2 needs to play 'a+1,a+2 ..., a+b,1,...,a,a+b+1,...,n'

### 3419 Mex Grid Construction

### 3217 Knight Moves Grid

### 3311 Grid coloring

Greedy approach to color the grid such that no two adjacent cells have the same color.

### 2431 Digit Queries

Find which group a digit belongs to, 1 digit, 2 digits, etc., each group containing 9\*10^k digits for k = 0, 1, 2, ...
Then find the number in that group and the specific digit within that number.

### 1743 String reorder

Always starting from 'A' to 'Z', Count the frequencies of each letter.

Using backtracking, place the smallest letter possible, otherwiese try the next one.

### 1625 Grid path description
