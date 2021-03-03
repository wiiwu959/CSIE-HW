import sys
import random
import math

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

def chineseRemainderTheorem(y, p, q, d):
    dp = d % (p - 1)
    dq = d % (q - 1)

    xp = squareAndMultiply(y, dp, p)
    xq = squareAndMultiply(y, dq, q)

    t = modInverse(p, q)
    u = ((xq- xp) * t ) % q
    x = xp + p * u
    return x

def init(keylength):
    p_length = keylength / 2
    q_length = (keylength / 2 + keylength % 2 + 1)
    p = generateLargePrime(p_length)
    q = generateLargePrime(q_length)
    n = p * q
    
    while(n < (2 ** (keylength - 1))) or (n > (2 ** keylength)):
        p = generateLargePrime(p_length)
        q = generateLargePrime(q_length)
        n = p * q

    phi_n = (p - 1) * (q - 1)
    e = 0
    for i in (range(2, phi_n)):
        if math.gcd(i, phi_n) == 1:
            e = i
            break
    d = modInverse(e, phi_n)

    print(' p = ', p, '\n', 'q = ', q, '\n', 'n = ', n, '\n', 'e = ', e, '\n', 'd = ', d)

def encrypt(plaintext, n, e):
    ciphertext = ''
    for i in plaintext:
        ciphertext += str((squareAndMultiply(ord(i), e, n))) + '/'
    print('\nYour ciphertext is :')
    print(ciphertext)

def decrypt(ciphertext, p, q, d):
    ciphertext = ciphertext.split('/')[:-1]
    plaintext = ''
    for i in ciphertext:
        plaintext += chr((chineseRemainderTheorem(int(i), p, q, d)))

    print('\nYour plaintext is :')
    print(plaintext)


action = sys.argv[1]

if action == 'init':
    if len(sys.argv) == 3:
        keylength = int(sys.argv[2])
    else:
        keylength = 1024
    init(keylength)

elif action == '-e':
    plaintext = sys.argv[2]
    n = int(sys.argv[3])
    e = int(sys.argv[4])
    encrypt(plaintext, n, e)

elif action == '-d':
    ciphertext = sys.argv[2]
    p = int(sys.argv[3])
    q = int(sys.argv[4])
    d = int(sys.argv[5])
    decrypt(ciphertext, p, q, d)