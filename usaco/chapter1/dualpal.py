"""
ID: juniory1
LANG: PYTHON3
TASK: dualpal
"""


def is_palindrome(s):
    """Check if a string is a palindrome"""
    return s == s[::-1]


def convert_to_base(num, base):
    """Convert a number to the given base representation"""
    if num == 0:
        return "0"
    digits = []
    while num:
        digits.append(str(num % base) if num %
                      base < 10 else chr(ord('A') + num % base - 10))
        num //= base
    return ''.join(digits[::-1])


def is_dual_palindrome(num):
    """Check if number is palindrome in at least 2 different bases (2-10)"""
    palindrome_count = 0
    for base in range(2, 11):
        if is_palindrome(convert_to_base(num, base)):
            palindrome_count += 1
            if palindrome_count >= 2:
                return True
    return False


# File I/O
with open('dualpal.in', 'r') as fin:
    N, S = map(int, fin.readline().split())

# Find N numbers greater than S that are dual palindromes
count = 0
num = S + 1
results = []

while count < N:
    if is_dual_palindrome(num):
        results.append(str(num))
        count += 1
    num += 1

# Write output
with open('dualpal.out', 'w') as fout:
    fout.write('\n'.join(results) + '\n')
