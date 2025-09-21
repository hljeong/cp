l, m = map(int, input().split())
mowers = []
for i in range(m): 
  mowers.append(tuple(input().split(',')))
mowers.sort(key=lambda mo: int(mo[1]))

def gcd(a, b): 
  if b == 0: return a
  return gcd(b, a % b)

if False: 
  def works(s, c, t, r): 
    mow = (10080 - s) // (t + r) * c * t
    mow += max(0, t - s) * c
    mow += min(t, (10080 - s) % (t + r)) * c
    return mow >= l

  def check(mo): 
    _, __, c, t, r = mo
    c, t, r = map(int, (c, t, r))
    step = gcd(10080, t + r)
    for i in range(0, t + r, step): 
      if not works(i, c, t, r): return False
    return True

def check(mo): 
  _, __, c, t, r = mo
  c, t, r = map(int, (c, t, r))
  cycle = (t + r) // gcd(10080, t + r)
  for i in range(cycle): 
    tt = (i + 1) * 10080
    mow = tt // (t + r) * c * t
    mow += min(t, tt % (t + r)) * c
    if mow < (i + 1) * l: return False
  return True

mx = 1000000
for mo in mowers: 
  if int(mo[1]) > mx: break
  if check(mo): 
    print(mo[0])
    mx = int(mo[1])
if mx == 1000000: print('no such mower')
