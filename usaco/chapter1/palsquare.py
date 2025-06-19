"""
ID: juniory1
LANG: PYTHON3
TASK: palsquare
"""


def to_base_b(num, b):
    """Convert number to base b, using A-Z for digits 10-20"""
    if num == 0:
        return "0"
    digits = []
    while num:
        digit = num % b
        if digit < 10:
            digits.append(str(digit))
        else:
            digits.append(chr(ord('A') + digit - 10))
        num //= b
    return ''.join(digits[::-1])


def is_palindrome(s):
    """Check if string is palindrome"""
    return s == s[::-1]


def solve(b):
    result = []
    # Check all numbers from 1 to 300
    for n in range(1, 301):
        # Convert n^2 to base b
        square = n * n
        square_base_b = to_base_b(square, b)
        # If square is palindrome, add to results
        if is_palindrome(square_base_b):
            result.append((n, square_base_b))
    return result


# File I/O
with open('palsquare.in', 'r') as fin:
    B = int(fin.readline().strip())

with open('palsquare.out', 'w') as fout:
    for num, square in solve(B):
        fout.write(f"{to_base_b(num, B)} {square}\n")
