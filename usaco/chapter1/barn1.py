"""
ID: juniory1
LANG: PYTHON3
TASK: barn1
"""


def solve_barn():
    with open('barn1.in', 'r') as fin:
        M, S, C = map(int, fin.readline().split())
        # M = max boards allowed
        # S = total stalls
        # C = number of occupied stalls

        # Read occupied stall positions
        occupied = []
        for _ in range(C):
            stall = int(fin.readline())
            occupied.append(stall)

    # If we have enough boards to cover each stall individually
    if M >= C:
        result = C
    else:
        # Sort occupied stalls
        occupied.sort()

        # Find gaps between occupied stalls
        gaps = []
        for i in range(1, len(occupied)):
            # we count the empty stalls that can skip
            gap = occupied[i] - occupied[i-1] - 1
            if gap > 0:
                gaps.append(gap)

        # Sort gaps in descending order
        gaps.sort(reverse=True)

        total_stalls = occupied[-1] - occupied[0] + 1

        # we split the stalls into M groups, with M-1 gaps
        for i in range(min(M-1, len(gaps))):
            total_stalls -= gaps[i]

        result = total_stalls

    # Write output to barn1.out
    with open('barn1.out', 'w') as fout:
        fout.write(f'{result}\n')


if __name__ == '__main__':
    solve_barn()
