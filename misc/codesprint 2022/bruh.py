import os
import math

for i in range(11, 31): 
  os.system('amogoursgen.exe %d' % i)
  os.system('java among_ourselves <secret.%d.in >secret.%d.ans' % (i, i))
  f = open('secret.%d.ans' % i, 'r')
  c = f.readline()[0]
  cnt = 1
  while (c == '-' or c == '1'): 
    f.close()
    os.system('amogoursgen.exe %d' % i)
    os.system('java among_ourselves <secret.%d.in >secret.%d.ans' % (i, i))
    f = open('secret.%d.ans' % i, 'r')
    c = f.readline()[0]
    cnt = cnt + 1
    lgcnt = math.log2(cnt)
    if (math.ceil(lgcnt) == math.floor(lgcnt)): 
      print('attempt %d' % cnt)
  print('finished %d' % i)
