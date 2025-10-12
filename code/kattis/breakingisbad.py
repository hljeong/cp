# ucla tryout #1 2025 virtual

import sys

n = int(input())
lines = []
for line in sys.stdin:
    lines.append(line.rstrip())

assert len(lines) == n

ans = 10000000000000000000
for line in lines:
    b = 0
    last_t = None
    for thing in line.split():
        left, right = thing.split("-")
        lh, lm = map(int, left.split(":"))
        rh, rm = map(int, right.split(":"))
        ltime = lh * 60 + lm
        rtime = rh * 60 + rm
        if last_t is not None:
            b += ltime - last_t
        last_t = rtime
    if b < ans:
        ans = b

print(ans)
