"""
ID: juniory1
LANG: PYTHON3
TASK: wormhole
"""


def next_on_right(x, y, wormholes):
    """
    Find the next wormhole directly to the right of position (x,y).
    Returns None if there is no wormhole to the right.
    """
    next_hole = None
    next_x = float('inf')

    for wx, wy in wormholes:
        if wy == y and wx > x and wx < next_x:
            next_hole = (wx, wy)
            next_x = wx

    return next_hole


def has_cycle(wormholes, pairs):
    """
    Check if the given wormhole pairing creates any cycles.
    """
    for start_x, start_y in wormholes:
        pos = (start_x, start_y)
        visited = set()

        while True:
            next_hole = next_on_right(pos[0], pos[1], wormholes)
            if next_hole is None:
                break
            if next_hole in visited:
                return True
            visited.add(next_hole)
            pos = pairs[next_hole]

    return False


def solve(wormholes):
    """
    Generate all possible pairings and count those that create cycles.
    Returns the total number of possible pairings that create cycles.
    """
    def generate_pairings(unpaired, pairs):
        # Base case: all wormholes are paired
        if not unpaired:
            if has_cycle(wormholes, pairs):
                return 1
            return 0

        total = 0
        first = unpaired[0]  # Take first unpaired wormhole

        # Try pairing it with each remaining unpaired wormhole
        for i in range(1, len(unpaired)):
            second = unpaired[i]

            # Create new pairing
            new_pairs = pairs.copy()
            new_pairs[first] = second
            new_pairs[second] = first

            # Remove both wormholes from unpaired list
            new_unpaired = unpaired[1:i] + unpaired[i+1:]

            # Recursively generate remaining pairings
            total += generate_pairings(new_unpaired, new_pairs)

        return total

    return generate_pairings(list(wormholes), {})


with open('wormhole.in', 'r') as fin:
    N = int(fin.readline().strip())
    wormholes = []
    for _ in range(N):
        x, y = map(int, fin.readline().split())
        wormholes.append((x, y))

result = solve(wormholes)

with open('wormhole.out', 'w') as fout:
    fout.write(f'{result}\n')
