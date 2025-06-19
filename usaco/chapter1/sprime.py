"""
ID: juniory1
LANG: PYTHON3
TASK: sprime
"""


def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    # Check odd numbers up to sqrt(n)
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def generate_sprimes(n, current=0):
    if len(str(current)) == n:
        return [current]

    result = []
    # First digit can't be 0 or even (except 2)
    digits = [1, 2, 3, 5, 7, 9] if current == 0 else [1, 3, 5, 7, 9]

    for d in digits:
        next_num = current * 10 + d
        if is_prime(next_num):
            result.extend(generate_sprimes(n, next_num))

    return result


with open('sprime.in', 'r') as fin:
    N = int(fin.readline().strip())

sprimes = generate_sprimes(N)

with open('sprime.out', 'w') as fout:
    for sprime in sorted(sprimes):
        fout.write(f'{sprime}\n')
