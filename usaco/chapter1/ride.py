"""
ID: juniory1
LANG: PYTHON3
TASK: ride
"""


def solve(s1, s2):
    def compute_mod(s):
        result = 1
        for c in s:
            result = (result * (ord(c) - ord('A') + 1)) % 47
        return result

    if (compute_mod(l1) == compute_mod(l2)):
        return "GO"
    else:
        return "STAY"


with open("ride.in", "r") as fin:
    l1 = fin.readline().strip()
    l2 = fin.readline().strip()

result = solve(l1, l2)

with open("ride.out", "w") as fout:
    fout.write(result + "\n")
