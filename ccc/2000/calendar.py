import sys


def get_input():
    begin, days = map(int, sys.stdin.readline().strip().split(" "))
    return begin, days


def print_body(begin, days):
    line = ""
    for i in range(1, days + begin):
        if i < begin:
            line += " " * 3 + " "
            continue
        if i % 7 == 0:
            line += f"{(i - begin + 1):3}"
            print(line.rstrip())
            line = ""
            continue
        line += f"{(i - begin + 1):3}" + " "
    if line != "":
        print(line.rstrip())


def print_header():
    print("Sun Mon Tue Wed Thr Fri Sat")


def solve():
    begin, days = get_input()
    print_header()
    print_body(begin, days)


if __name__ == '__main__':
    solve()
