"""
ID: juniory1
LANG: PYTHON3
TASK: skidesign
"""


def solve(hills):
    min_cost = float('inf')

    # Try all possible ranges of size 17
    for min_height in range(84):  # 0 to 83
        max_height = min_height + 17
        cost = 0

        # Calculate cost for this range
        for hill in hills:
            if hill < min_height:
                # Cost to increase height
                diff = min_height - hill
                cost += diff * diff
            elif hill > max_height:
                # Cost to decrease height
                diff = hill - max_height
                cost += diff * diff

        min_cost = min(min_cost, cost)

    return min_cost


# Read input and write output
with open('skidesign.in', 'r') as fin:
    N = int(fin.readline().strip())
    hills = []
    for _ in range(N):
        hills.append(int(fin.readline().strip()))

result = solve(hills)

with open('skidesign.out', 'w') as fout:
    fout.write(f'{result}\n')
