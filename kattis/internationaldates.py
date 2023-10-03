d = list(map(int, input().split('/')))
if d[0] > 12: 
  print('EU')
elif d[1] > 12: 
  print('US')
else: 
  print('either')
