for x in range(1 << 6): 
  s = ''.join(['000000', '{0:b}'.format(x)])[-6:]
  b = [ord(c) - ord('0') for c in s]
  if all(b[i] == (b[i - 3] + b[i - 2] + b[i - 1]) % 2 for i in range(3, 6)): 
    print(s)