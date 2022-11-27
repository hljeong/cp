from collections import defaultdict
from math import sqrt

a, c = map(int, input().split())
oa, oc = a, c
ps = set()
d = [0] * 1000001
for i in range(2, 1000001): 
  if d[i] == 0: 
    ps.add(i)
    j = i * i
    while j <= 1000000: 
      d[j] = i
      j += i
pa, pc = defaultdict(lambda: 0), defaultdict(lambda: 0)
for p in ps: 
  while a % p == 0: 
    pa[p] += 1
    a //= p
  while c % p == 0: 
    pc[p] += 1
    c //= p

pav, pcv = [(k, v) for k, v in pa.items()], [(k, v) for k, v in pc.items()]

da, dc = set(), set()
def get(i, cur, pv, d): 
  if i == len(pv): 
    d.add(cur)
    return
  ppd = 1
  for j in range(pv[i][1] + 1): 
    get(i + 1, cur * ppd, pv, d)
    ppd *= pv[i][0]

get(0, 1, pav, da)
get(0, 1, pcv, dc)
g = set()

mod = 1000000007

def tr(x, y): 
  z, w = oa // x, oc // y
  x %= mod
  y %= mod
  z %= mod
  w %= mod
  b = x * w % mod + y * z % mod
  if b >= mod: b -= mod
  if b in g: return
  g.add(b)
  g.add(-b)

for x in da: 
  for y in dc: 
    tr(x, y)

print(len(g))
