# encoding: utf-8

num = input('Type the number: ') # num是一個字串
numlist = list(num) # numlist是由字元組成的list
checklist = [True for i in range(10)] # 長度為10、值都是True的list
if len(numlist) != 10:
 print('Illegal input: wrong length')
 exit(1)
for i in numlist:
 if not i.isdigit():
  print('Illegal input: ', i, 'is not a digit')
  exit(2)
 else: checklist[int(i)] = False
if any(checklist):
 print('Illegal input: repeated digit')
 exit(3)
if (numlist == ['9','8','7','6','5','4','3','2','1','0']):
 print('This is the largest value.')
 exit(4)
n = int(9)
k = int(9)
while(numlist[n-1] > numlist[n]):
 n = n-1
while(numlist[n-1] > numlist[k]):
 k = k-1
(numlist[n-1], numlist[k]) = (numlist[k], numlist[n-1])
numlist = numlist[0:n] + sorted(numlist[n:])
print(numlist)