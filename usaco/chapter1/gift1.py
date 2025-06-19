"""
ID: juniory1
LANG: PYTHON3
TASK: gift1
"""

# Open input and output files
with open('gift1.in', 'r') as fin, open('gift1.out', 'w') as fout:
    # Read number of people
    NP = int(fin.readline().strip())

    # Create dictionary to store money for each person
    money = {}
    # Store names in order of appearance
    names = []

    # Read names of all people
    for _ in range(NP):
        name = fin.readline().strip()
        names.append(name)
        money[name] = 0

    # Process gift giving
    for _ in range(NP):
        # Read giver's name
        giver = fin.readline().strip()
        # Read amount and number of recipients
        amount, n_people = map(int, fin.readline().strip().split())

        # If no recipients or no money, skip
        if n_people == 0:
            continue

        # Calculate gift amount per person
        gift = amount // n_people
        # Calculate money kept by giver (remainder)
        kept = amount % n_people

        # Subtract total gift amount from giver
        money[giver] -= amount
        # Add back the remainder
        money[giver] += kept

        # Process recipients
        for _ in range(n_people):
            recipient = fin.readline().strip()
            money[recipient] += gift

    # Write results to output file
    for name in names:
        fout.write(f'{name} {money[name]}\n')
