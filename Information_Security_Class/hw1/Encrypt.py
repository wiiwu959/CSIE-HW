import sys
import math

cipher = sys.argv[1]
key = sys.argv[2]
plaintext = sys.argv[3]

ans = ''
block = []

# caesar cipher
if cipher == 'caesar':
	for i in plaintext:
		ans += chr((ord(i) - ord('a') + int(key)) % 26 + 65)
	print (ans,end='')

# playfair cipher
elif cipher == 'playfair':
	tmp = key
	tmp.replace('J','I')
	key = ''
	for i in tmp:
		if (key.find(i) == -1):
			key += i

	for i in range(65, 91):
		if (key.find(chr(i)) == -1) & (i != 74):
			key += chr(i)

	plaintext.replace('j','i')
	plaintext = plaintext.upper()
	for i in range (0, len(plaintext), 2):
		p1 = key.find(plaintext[i])
		p2 = key.find(plaintext[i + 1])
		if int(p1/5) == int(p2/5):
			if (p1 % 5 + 1) == 5:
				ans += key[p1 - 4]
			else:
				ans += key[p1 + 1]
			if (p2 % 5 + 1) == 5:
				ans += key[p2 - 4]
			else:
				ans += key[p2 + 1]
		elif p1 % 5 == p2 % 5:
			if (p1 + 5) > 24:
				ans += key[p1 % 5]
			else:
				ans += key[p1 + 5]
			if (p2 + 5) > 24:
				ans += key[p2 % 5]
			else:
				ans += key[p2 + 5]
		else:
			row1 = int(p1 / 5)
			col1 = p1 % 5
			row2 = int(p2 / 5)
			col2 = p2 % 5
			ans += key[(row1) * 5 + col2]
			ans += key[(row2) * 5 + col1]
	print(ans,end='')


# vernam cipher
elif cipher == 'vernam':
	n = 0
	k = 0
	for i in plaintext:
		if n < len(key):
			ans += chr((ord(i) + ord(key[n]) - 162) % 26 + 65)
			n += 1
		else:
			ans += chr((ord(i) + ord(plaintext[k]) - 194 ) % 26 + 65)
			k += 1
	print (ans,end='')

# row cipher
elif cipher == 'row':
	plaintext += ' ' * (len(key) - len(plaintext) % len(key))
	for i in range (len(key)):
		block.append([])


	for n in range (len(key)):
		for i in range (math.ceil(len(plaintext)/len(key))):
			block[int(key[n]) - 1].append(plaintext[n + len(key) * i])

	for i in range (len(block)):
		for n in block[i]:
			if n !=' ':
				print (n.upper(), end='')

# rail fence cipher
elif cipher == 'rail_fence':
	fence = int(key) - 1
	block = []
	for i in range (fence + 1):
		block.append([])

	n = 0
	flag = True
	for i in plaintext:
		block[n].append(i)
		if flag == True:
			if n != fence:
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

	for i in range (len(block)):
		for n in block[i]:
			print (n.upper(), end='')
