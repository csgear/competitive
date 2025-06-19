"""
ID: juniory1
LANG: PYTHON3
TASK: friday
"""

with open("friday.in", "r") as fin, open("friday.out", "w") as fout:
    N = int(fin.readline().strip())
    current_day = 2
    days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    day_counts = [0] * 7

    # 13th
    for year in range(1900, 1900 + N):
        for month in range(12):
            thirteenth_day = (current_day + 12) % 7
            day_counts[thirteenth_day] += 1
            if month == 1:  # February
                # Check for leap year
                if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
                    current_day = (current_day + 29) % 7
                else:
                    current_day = (current_day + 28) % 7
            else:
                current_day = (current_day + days_in_month[month]) % 7

    fout.write(" ".join(map(str, day_counts)) + "\n")
