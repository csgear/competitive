"""
ID: juniory1
LANG: PYTHON3
TASK: combo
"""


def is_close(a, b, n):
    # Check if two numbers are within 2 positions of each other (circular)
    diff = abs(a - b)
    return diff <= 2 or diff >= n - 2


def is_valid_combo(guess, actual, n):
    # Check if a combination is close enough to work
    return (is_close(guess[0], actual[0], n) and
            is_close(guess[1], actual[1], n) and
            is_close(guess[2], actual[2], n))


def solve():
    # Read input
    with open('combo.in', 'r') as fin:
        n = int(fin.readline().strip())
        farmer = list(map(int, fin.readline().strip().split()))
        master = list(map(int, fin.readline().strip().split()))

    # Count valid combinations
    valid_combos = set()

    # Check all possible combinations
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                combo = (i, j, k)
                # Add to set if it works for either lock
                if (is_valid_combo(combo, farmer, n) or
                        is_valid_combo(combo, master, n)):
                    valid_combos.add(combo)

    # Write output
    with open('combo.out', 'w') as fout:
        fout.write(f'{len(valid_combos)}\n')


if __name__ == '__main__':
    solve()
