import sys

N = int(sys.stdin.readline())

scores = []

for _ in range(N):
    scores.append(int(sys.stdin.readline()))

unique_scores = sorted(set(scores), reverse=True)

bronze_score = unique_scores[2]

bronze_count = scores.count(bronze_score)

print(bronze_score, bronze_count)
