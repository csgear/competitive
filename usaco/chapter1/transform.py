"""
ID: juniory1
LANG: PYTHON3
TASK: transform
"""


def rotate_90(pattern):
    n = len(pattern)
    result = [['' for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n-1-i] = pattern[i][j]
    return result


def rotate_180(pattern):
    n = len(pattern)
    result = rotate_90(pattern)
    result = rotate_90(result)
    return result


def rotate_270(pattern):
    n = len(pattern)
    result = [['' for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[n-1-j][i] = pattern[i][j]
    return result


def reflect(pattern):
    n = len(pattern)
    result = [['' for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[i][n-1-j] = pattern[i][j]
    return result


def are_equal(pattern1, pattern2):
    return pattern1 == pattern2


def find_transformation(before, after):
    # #1: 90 Degree Rotation
    if are_equal(rotate_90(before), after):
        return 1

    # #2: 180 Degree Rotation
    if are_equal(rotate_180(before), after):
        return 2

    # #3: 270 Degree Rotation
    if are_equal(rotate_270(before), after):
        return 3

    # #4: Reflection
    if are_equal(reflect(before), after):
        return 4

    # #5: Combination
    reflected = reflect(before)
    if (are_equal(rotate_90(reflected), after) or
        are_equal(rotate_180(reflected), after) or
            are_equal(rotate_270(reflected), after)):
        return 5

    # #6: No Change
    if are_equal(before, after):
        return 6

    # #7: Invalid
    return 7

# Example usage:


# Read input
with open('transform.in', 'r') as fin:
    n = int(fin.readline())
    before = []
    after = []
    # Read before pattern
    for _ in range(n):
        before.append(list(fin.readline().strip()))

    # Read after pattern
    for _ in range(n):
        after.append(list(fin.readline().strip()))

# Find and print the transformation number
result = find_transformation(before, after)
# Write output to transform.out
with open('transform.out', 'w') as fout:
    fout.write(f'{result}\n')
