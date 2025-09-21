n, p = map(int, input().split())
c, m, a = set(), set(), set()

for i in range(n): 
  line = input().split()
  if line[1] == 'c': c.add(line[0])
  else: m.add(line[0])
  a.add(line[0])

def pr(good): 
  if good: print('Correct!')
  else: print('Not on my watch!')

check = {
  'number': c, 
  'amount': m, 
  'most': a, 
  'fewest': c, 
  'least': m, 
  'more': a, 
  'fewer': c, 
  'less': m, 
  'many': c, 
  'much': m, 
  'few': c, 
  'little': m
}

for i in range(p):  
  line = input().split()
  pr(line[-1] in check[line[0]])
