"""
ID: juniory1
LANG: PYTHON3
TASK: namenum
"""

# Dictionary mapping numbers to possible letters (like old phone keypad)
KEYPAD = {
    '2': ['A', 'B', 'C'],
    '3': ['D', 'E', 'F'],
    '4': ['G', 'H', 'I'],
    '5': ['J', 'K', 'L'],
    '6': ['M', 'N', 'O'],
    '7': ['P', 'R', 'S'],
    '8': ['T', 'U', 'V'],
    '9': ['W', 'X', 'Y']
}


def get_possible_names(number):
    # Read the dictionary of valid names
    valid_names = set()
    with open('dict.txt', 'r') as f:
        for line in f:
            valid_names.add(line.strip())

    # Find all valid names that match the number
    result = []

    def generate_names(curr_name, remaining_digits):
        if not remaining_digits:
            if curr_name in valid_names:
                result.append(curr_name)
            return

        digit = remaining_digits[0]
        if digit not in KEYPAD:
            return

        for letter in KEYPAD[digit]:
            generate_names(curr_name + letter, remaining_digits[1:])

    generate_names('', number)
    return sorted(result)


# Read input
with open('namenum.in', 'r') as fin:
    number = fin.readline().strip()

# Get possible names
valid_names = get_possible_names(number)

# Write output
with open('namenum.out', 'w') as fout:
    if valid_names:
        for name in valid_names:
            fout.write(f'{name}\n')
    else:
        fout.write('NONE\n')
