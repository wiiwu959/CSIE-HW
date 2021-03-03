import sys
import random
import math
import hashlib

def generateLargePrime(keylength):
    while True:
        # generate random bits
        num = random.getrandbits(int(keylength))
        # apply a mask to set MSB and LSB to 1
        num |= (1 << int(keylength) - 1) | 1
        if isPrime(num):
            return num

def isPrime(num):
    if (num < 2):
        return False
    primelist = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 
                67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
                157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 
                251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,317, 331, 337, 347, 349, 
                353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 
                457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 
                571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 
                673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 
                797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 
                911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]
    if num in primelist:
        return True
    for prime in primelist:
        if (num % prime == 0):
            return False
    return millerRabin(40, num)

def millerRabin(times, num):
    m = num -1
    k = 0
    while m % 2 == 0:
        m = m // 2
        k += 1
        
    for i in range(times):
        a = random.randrange(2, num - 1)
        b = squareAndMultiply(a, m, num)
        if (b != 1) and (b != num - 1):
            i = 1
            while i < k and b != num - 1:
                b = squareAndMultiply(b, b, num)
                if b == 1:
                    return False
                i += 1
            if b != num - 1:
                return False
    return True

# y = (x ** h) mod n
def squareAndMultiply(x, h, n):
    h = bin(h).lstrip('0b')
    h = h[1:]
    y = x
    for i in h:
        y = (y ** 2) % n
        if i == '1':
            y = (y * x) % n
    return y

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modInverse(a, b):
    g, x, y = egcd(a, b)
    if g == 1:
        return x % b

def findOrd(p,q):
    for h in range(2, p-1):
        a = squareAndMultiply(h, (p-1) // q, p)  # a = h ** ((p − 1)/q) % p
        if(squareAndMultiply(a, q, p) == 1):  # a**q = 1 mod p 
            return a

def keygen(keylength):
    q = generateLargePrime(keylength)
    p = q << (1024-160)
    while (not (isPrime(p + 1)) and (len(bin(p)[2:]) == 1024)):
        p = p + q
    p = p + 1

    while ((len(bin(p)[2:]) != 1024)):
        q = generateLargePrime(keylength)
        p = q << (1024-160)
        while (not (isPrime(p + 1)) and (len(bin(p)[2:]) == 1024)):
            p = p + q
        p = p + 1

    a = findOrd(p, q)
    d = random.randrange(1,q)
    b = squareAndMultiply(a, d, p)  #(b = a**d % p)

    fp = open("publicKey.txt", "w")
    flur = str(p) + '\n' + str(q) + '\n' + str(a) + '\n' + str(b)
    fp.write(flur)
    fp.close()
    fp = open("privateKey.txt", "w")
    flur = str(d) + '\n'
    fp.write(flur)
    fp.close()
    print('p = ', p)
    print('q = ', q)
    print('a = ', a)
    print('b = ', b)
    print('d = ', d)
    print('Public key is store in publicKey.txt, and private key is store in privateKey.txt.')

def generation(message):
    fp = open("publicKey.txt", "r")
    text = fp.readline()
    p = int(text)
    text = fp.readline()
    q = int(text)
    text = fp.readline()
    a = int(text)
    text = fp.readline()
    b = int(text)
    fp.close()
    fp = open("privateKey.txt", "r")
    text = fp.read()
    d = int(text)
    fp.close()

    k = random.randrange(1, q)
    r = squareAndMultiply(a, k, p) % q # (a^k mod p) mod q 
    h = int(hashlib.sha1(message.encode("utf8")).hexdigest(), 16)
    s = ((h + d * r) * modInverse(k, q)) % q  # s ≡ (SHA(x) + d * r) * k^-1 mod q 
    fp = open("signature.txt", "w")
    flur = str(r) + '\n' + str(s)
    fp.write(flur)
    print('r = ', r)
    print('s = ', s)
    print('Signature is store in signature.txt.')

def verification(message):
    fp = open("publicKey.txt", "r")
    text = fp.readline()
    p = int(text)
    text = fp.readline()
    q = int(text)
    text = fp.readline()
    a = int(text)
    text = fp.readline()
    b = int(text)
    fp.close()
    fp = open("signature.txt", "r")
    text = fp.readline()
    r = int(text)
    text = fp.readline()
    s = int(text)
    fp.close()

    w = (modInverse(s, q)) % q  # w ≡ s – 1 mod q
    h = int(hashlib.sha1(message.encode("utf8")).hexdigest(), 16)
    u1 = w * h % q  # u1 ≡ w * SHA(x) mod q 
    u2 = w * r % q  # u2 ≡ w * r mod q
    v = ((squareAndMultiply(a, u1, p)*squareAndMultiply(b, u2, p)) % p) % q  # v ≡ (a^u1 * b^u2 mod p) mod q
    if (v == r):
        print ('valid')
    else:
        print ('invalid') 


action = sys.argv[1]

if action == '-keygen':
    if len(sys.argv) == 3:
        keylength = int(sys.argv[2])
    else:
        keylength = 160
    keygen(keylength)

elif action == '-sign':
    message = sys.argv[2]
    generation(message)

elif action == '-verify':
    message = sys.argv[2]
    verification(message)