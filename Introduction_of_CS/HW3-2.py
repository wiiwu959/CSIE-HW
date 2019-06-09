# encoding: utf-8

Last = 0
Current = 1
n = 1
k = int(input())
while (Current<k):
 Temp = Last
 Last = Current
 Current = Last + Temp
 n = n+1
if (k == Current):
 print ("yes",n)
elif (k != Current):
 print ("no")
