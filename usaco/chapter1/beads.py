"""
ID: juniory1
LANG: PYTHON3
TASK: beads
"""


def max_beads_n(necklace):
    '''using DP to archieve O(N)'''
    # Duplicate the necklace to handle circularity
    n = len(necklace)
    s = necklace + necklace

    # Initialize left and right DP arrays
    # left[i][0] for 'r', left[i][1] for 'b'
    left = [[0] * 2 for _ in range(2 * n + 1)]
    # right[i][0] for 'r', right[i][1] for 'b'
    right = [[0] * 2 for _ in range(2 * n + 1)]

    # Fill the left array
    for i in range(1, 2 * n + 1):
        if s[i - 1] == 'r':
            left[i][0] = left[i - 1][0] + 1
            left[i][1] = 0
        elif s[i - 1] == 'b':
            left[i][1] = left[i - 1][1] + 1
            left[i][0] = 0
        else:  # 'w' case
            left[i][0] = left[i - 1][0] + 1
            left[i][1] = left[i - 1][1] + 1

    # Fill the right array
    for i in range(2 * n - 1, -1, -1):
        if s[i] == 'r':
            right[i][0] = right[i + 1][0] + 1
            right[i][1] = 0
        elif s[i] == 'b':
            right[i][1] = right[i + 1][1] + 1
            right[i][0] = 0
        else:  # 'w' case
            right[i][0] = right[i + 1][0] + 1
            right[i][1] = right[i + 1][1] + 1

    # Calculate the maximum beads
    m = 0
    for i in range(2 * n):
        m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]))
    m = min(m, n)  # Ensure we do

    return m


def max_beads_n2(necklace):
    '''O(N^2) brute force'''
    necklace += necklace
    n = len(necklace)
    max_count = 0

    for i in range(n-1):
        left = i
        current_color = necklace[left]
        count_left = 0
        while left >= 0 and (necklace[left] == current_color or necklace[left] == 'w'):
            count_left += 1
            left -= 1
            if left < 0:
                break
            if current_color == 'w' and necklace[left] != 'w':
                current_color = necklace[left]

        right = i + 1
        current_color = necklace[right]
        count_right = 0
        while right < n and (necklace[right] == current_color or necklace[right] == 'w'):
            count_right += 1
            right += 1
            if right >= n:
                break
            if current_color == 'w' and necklace[right] != 'w':
                current_color = necklace[right]

        total = count_left + count_right
        if total > max_count:
            max_count = total
        # Ensure we don't exceed the necklace length
        if max_count >= n / 2:
            max_count = n // 2
            break

    return max_count


with open("beads.in", "r") as fin, open("beads.out", "w") as fout:
    n = fin.readline().strip()
    necklace = fin.readline().strip()
    fout.write(str(max_beads_n(necklace)))
    fout.write("\n")
