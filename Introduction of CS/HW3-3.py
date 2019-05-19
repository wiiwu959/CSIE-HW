# encoding: utf-8
# 參考出處:https://ifun01.com/8ZYBHFD.html和維基百科

def hanoi(n, A, B, C):
 if n == 1:
  return [(A, C)]
 else:
  return hanoi(n-1, A, C, B) + hanoi(1, A, B, C) + hanoi(n-1, B, A, C)

number = input('How many rings ? ')
for move in hanoi(int(number), 'A', 'B', 'C'):
 message = 'From {first} move to {second}'.format(first=move[0], second=move[1])
 print(message)