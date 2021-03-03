import sys
import math

cipher = sys.argv[1]
key = sys.argv[2]
ciphertext = sys.argv[3]

ans = ''
block = []

# caesar cipher
if cipher == 'caesar':
	for i in ciphertext:
		ans += chr((ord(i) - ord('A') - int(key)) % 26 + 65)
	print (ans.lower(),end='')

# playfair cipher
elif cipher == 'playfair':
	tmp = key
	tmp.replace('J','I')
	key = ''
	for i in tmp:
		if (key.find(i) == -1):
			key += i

	for i in range(65, 91):
		if (key.find(chr(i)) == -1) and (i != 74):
			key += chr(i)

	ciphertext.replace('J','I')
	ciphertext = ciphertext.upper()
	for i in range (0, len(ciphertext), 2):
		p1 = key.find(ciphertext[i])
		p2 = key.find(ciphertext[i + 1])
		if int(p1/5) == int(p2/5):
			if (p1 % 5 - 1) == -1:
				ans += key[p1 + 4]
			else:
				ans += key[p1 - 1]
			if (p2 % 5 - 1) == -1:
				ans += key[p2 + 4]
			else:
				ans += key[p2 - 1]
		elif p1 % 5 == p2 % 5:
			if (p1 - 5) < 0:
				ans += key[p1 + 20]
			else:
				ans += key[p1 - 5]
			if (p2 - 5) < 0:
				ans += key[p2 + 20]
			else:
				ans += key[p2 - 5]
		else:
			row1 = int(p1 / 5)
			col1 = p1 % 5
			row2 = int(p2 / 5)
			col2 = p2 % 5
			ans += key[(row1) * 5 + col2]
			ans += key[(row2) * 5 + col1]
	print(ans.lower(),end='')

# vernam cipher
elif cipher == 'vernam':
	n = 0
	k = 0
	for i in ciphertext:
		if n < len(key):
			p = ord(i) - ord(key[n])
			if p < 0:
				p += 123
			else:
				p += 97
			n += 1
		else:
			p = ord(i) - ord(ans[k]) + 32
			if p < 0:
				p += 123
			else:
				p += 97
			k += 1
		ans += chr(p)
	print (ans,end='')

# row cipher
elif cipher == 'row':
	row = math.ceil(len(ciphertext) / len(key))
	for i in key:
		block.append([])

	x = 0
	less = len(ciphertext) % len(key)
	for i in range(len(key)):
		if i < less or less == 0:
			for j in range (row):
				block[int(i)].append(ciphertext[x])
				x += 1
		else:
			for j in range (row - 1):
				block[int(i)].append(ciphertext[x])
				x += 1
			block[int(i)].append(' ')

	for i in range(row):
		for j in key:
			n = block[int(j) - 1].pop(0) 
			if n != ' ':
				print(n.lower(),end='')

# rail fence cipher
elif cipher == 'rail_fence':
	fence = int(key)
	block = []
	for i in range(fence):
		block.append([])

	word = 0
	flag = True
	for x in range(int(key)):
		n = 0
		for i in range(len(ciphertext)):
			if n == x:
				block[n].append(ciphertext[word])
				word += 1	
			
			if flag == True:
				if n != (fence - 1):
					n += 1
				else:
					flag = False
					n -= 1
			else:
				if n != 0:
					n -= 1
				else:
					flag = True
					n += 1		
	
	n = 0
	for i in ciphertext:
		x = block[n].pop(0)
		print(x.lower(),end='')
		if flag == True:
			if n != fence - 1:
				n += 1
			else:
				flag = False
				n -= 1
		else:
			if n != 0:
				n -= 1
			else:
				flag = True
				n += 1
		