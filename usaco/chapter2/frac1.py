# usaco/chapter2/frac1.py
"""
ID: juniory1
LANG: PYTHON3
TASK: frac1
"""

import math


def generate_fractions(N):
    fractions = set()
    for d in range(2, N + 1):
        for n in range(1, d):
            # Reduce the fraction to its simplest form
            gcd = math.gcd(n, d)
            simplified_n = n // gcd
            simplified_d = d // gcd
            fractions.add((simplified_n, simplified_d))
    return fractions


def sort_fractions(fractions):
    fractions_list = list(fractions)
    fractions_list.sort(key=lambda x: x[0] / x[1])
    return fractions_list


def solve1():
    with open("frac1.in", "r") as fin:
        N = int(fin.readline().strip())

    fractions = generate_fractions(N)
    sorted_fractions = sort_fractions(fractions)

    with open("frac1.out", "w") as fout:
        fout.write("0/1\n")  # The fraction 0/1 is always the smallest
        for n, d in sorted_fractions:
            fout.write(f"{n}/{d}\n")
        fout.write("1/1\n")


def genfrac(n1, d1, n2, d2, n, fout):
    if d1 + d2 > n:
        return

    genfrac(n1, d1, n1 + n2, d1 + d2, n, fout)
    fout.write(f"{n1 + n2}/{d1 + d2}\n")
    genfrac(n1 + n2, d1 + d2, n2, d2, n, fout)


def solov2():
    with open("frac1.in", "r") as fin, open("frac1.out", "w") as fout:
        n = int(fin.readline().strip())

        fout.write("0/1\n")
        genfrac(0, 1, 1, 1, n, fout)
        fout.write("1/1\n")


if __name__ == "__main__":
    solov2()
