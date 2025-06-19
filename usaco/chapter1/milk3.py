"""
ID: juniory1
LANG: PYTHON3
TASK: milk3
"""


def pour(amounts, capacities, from_idx, to_idx):
    """Pour milk from one bucket to another"""
    amount = min(amounts[from_idx], capacities[to_idx] - amounts[to_idx])
    new_amounts = list(amounts)
    new_amounts[from_idx] -= amount
    new_amounts[to_idx] += amount
    return tuple(new_amounts)


def solve(a_cap, b_cap, c_cap):
    capacities = (a_cap, b_cap, c_cap)
    # Start with A and B empty, C full
    start = (0, 0, c_cap)

    # Keep track of visited states and possible C amounts
    visited = set()
    possible_c = set()

    def dfs(amounts):
        if amounts in visited:
            return
        visited.add(amounts)

        # If bucket A is empty, add amount in C to possible results
        if amounts[0] == 0:
            possible_c.add(amounts[2])

        # Try all possible pours
        for i in range(3):
            for j in range(3):
                if i != j:
                    new_amounts = pour(amounts, capacities, i, j)
                    dfs(new_amounts)

    dfs(start)
    return sorted(possible_c)


def main():
    # Read input
    with open('milk3.in', 'r') as fin:
        a, b, c = map(int, fin.readline().split())

    # Solve and write output
    result = solve(a, b, c)
    with open('milk3.out', 'w') as fout:
        fout.write(' '.join(map(str, result)) + '\n')


if __name__ == '__main__':
    main()
