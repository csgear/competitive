import sys

dusa = int(sys.stdin.readline().strip())

all_line = sys.stdin.read().split('\n')

for line in all_line:
    yobis = int(line)
    if (dusa > yobis):
        dusa += yobis
    else:
        print(dusa)
        sys.exit()
