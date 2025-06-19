"""
ID: juniory1
LANG: PYTHON3
TASK: milk
"""


def solve(N, farmers):

    # Sort farmers by price (ascending)
    farmers.sort()

    total_cost = 0
    milk_collected = 0

    # Buy milk from cheapest to most expensive until we have enough
    for price, amount in farmers:
        if milk_collected >= N:
            break

        # Calculate how much milk we still need
        milk_needed = N - milk_collected
        # Buy either all available milk or just what we need
        milk_to_buy = min(amount, milk_needed)

        total_cost += price * milk_to_buy
        milk_collected += milk_to_buy

    return total_cost


with open('milk.in', 'r') as fin:
    # N = milk needed, M = number of farmers
    N, M = map(int, fin.readline().split())
    farmers = []
    for _ in range(M):
        price, amount = map(int, fin.readline().split())
        farmers.append((price, amount))

total_cost = solve(N, farmers)

# Write output to milk.out
with open('milk.out', 'w') as fout:
    fout.write(f'{total_cost}\n')
