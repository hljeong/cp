s = input()
sm, fr = s.find(':)'), s.find(':(')
if sm != -1 and fr != -1: 
  print('double agent')
elif sm != -1: 
  print('alive')
elif fr != -1: 
  print('undead')
else: 
  print('machine')
