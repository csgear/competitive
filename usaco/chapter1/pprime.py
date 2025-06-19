"""
ID: juniory1
LANG: PYTHON3
TASK: pprime
"""


def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def generate_palindromes(a, b):
    palindromes = []
    # Handle single digit palindromes
    for i in range(max(1, a), min(10, b + 1)):
        if is_prime(i):  # Only add if prime
            palindromes.append(i)

    # Handle multi-digit palindromes
    for length in range(2, len(str(b)) + 1):
        # Generate first half of palindrome
        start = 10 ** ((length - 1) // 2)
        end = 10 ** ((length + 1) // 2)

        for i in range(start, end):
            # Create palindrome by mirroring digits
            if length % 2 == 0:
                # Even length: mirror all digits
                s = str(i)
                num = int(s + s[::-1])
            else:
                # Odd length: don't mirror middle digit
                s = str(i)
                num = int(s + s[:-1][::-1])

            if a <= num <= b and is_prime(num):
                palindromes.append(num)

    return sorted(palindromes)


with open('pprime.in', 'r') as fin:
    a, b = map(int, fin.readline().split())

result = generate_palindromes(a, b)

with open('pprime.out', 'w') as fout:
    for num in result:
        fout.write(f'{num}\n')
