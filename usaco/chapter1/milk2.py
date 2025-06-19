"""
ID: juniory1
LANG: PYTHON3
TASK: milk2
"""


def solve(intervals):
    # Sort intervals by start time
    intervals.sort()
    # Merge overlapping intervals
    i = 0
    while i < len(intervals) - 1:
        curr_end = intervals[i][1]
        next_start = intervals[i+1][0]
        # If intervals overlap or are adjacent, merge them
        if curr_end >= next_start:
            # Merge by taking the later end time
            intervals[i] = (intervals[i][0], max(
                intervals[i][1], intervals[i+1][1]))
            # Remove the merged interval
            intervals.pop(i+1)
        else:
            i += 1

    # Find longest milking time
    max_milk = 0
    for start, end in intervals:
        max_milk = max(max_milk, end - start)

    # Find longest idle time
    max_idle = 0
    for i in range(len(intervals)-1):
        idle_time = intervals[i+1][0] - intervals[i][1]
        max_idle = max(max_idle, idle_time)

    return max_milk, max_idle


# Read input
with open('milk2.in', 'r') as fin:
    N = int(fin.readline().strip())
    intervals = []
    for _ in range(N):
        start, end = map(int, fin.readline().split())
        intervals.append((start, end))

max_milk, max_idle = solve(intervals)

# Write output
with open('milk2.out', 'w') as fout:
    fout.write(f'{max_milk} {max_idle}\n')
