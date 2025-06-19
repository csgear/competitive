"""
ID: juniory1
LANG: PYTHON3
TASK: numtri
"""


def solve():
    # Read input
    with open('numtri.in', 'r') as fin:
        R = int(fin.readline().strip())
        triangle = []
        for _ in range(R):
            row = list(map(int, fin.readline().strip().split()))
            triangle.append(row)

    # Dynamic programming: work from bottom to top
    # Each position will store the maximum sum possible starting from that position
    for row in range(R-2, -1, -1):  # Start from second to last row
        for col in range(len(triangle[row])):
            # Maximum sum at current position is current value plus max of two possible paths below
            triangle[row][col] += max(triangle[row+1]
                                      [col], triangle[row+1][col+1])

    # Write output
    with open('numtri.out', 'w') as fout:
        fout.write(f'{triangle[0][0]}\n')


if __name__ == '__main__':
    solve()
