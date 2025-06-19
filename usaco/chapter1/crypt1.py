"""
ID: juniory1
LANG: PYTHON3
TASK: crypt1
"""


def check_digits(num, valid_digits):
    # Check if all digits in num are in valid_digits
    return all(int(d) in valid_digits for d in str(num))


with open('crypt1.in', 'r') as fin, open('crypt1.out', 'w') as fout:
    N = int(fin.readline().strip())
    digits = list(map(int, fin.readline().strip().split()))

    count = 0
    for a in digits:
        for b in digits:
            for c in digits:
                abc = 100*a + 10*b + c
                for d in digits:
                    # Check first partial product
                    partial1 = abc * d
                    if partial1 > 999 or not check_digits(partial1, digits):
                        continue
                    for e in digits:
                        # Check second partial product
                        partial2 = abc * e
                        if partial2 > 999 or not check_digits(partial2, digits):
                            continue

                        # Check final product
                        final = abc * (10*d + e)
                        if final > 9999 or not check_digits(final, digits):
                            continue

                        count += 1

    fout.write(f'{count}\n')
