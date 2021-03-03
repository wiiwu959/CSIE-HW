import sys
from random import randrange, getrandbits
import math

#dp=p',k=檢驗次數
def Miller_Rabin(dp, k):
    # Test if n is not even.
    if dp == 2 or dp == 3:
        return True
    #質數非偶數
    if dp <= 1 or dp % 2 == 0:
        return False
    #找r和u
    u = 0
    r = dp - 1
    while r & 1 == 0:
        u += 1
        r //= 2
    #質數檢驗
    for _ in range(k):
        a = randrange(2, dp - 1)
        #x = pow(a, r, dp)  # a^r%dp
        x = Square_And_Multiply(a, r, dp)
        if x != 1 and x != dp - 1:
            j = 1
            while j < u and x != dp - 1:
                #x = pow(x, 2, dp)
                x = Square_And_Multiply(x, 2, dp)
                if x == 1:
                    return False
                j += 1
            if x != dp - 1:
                return False
    return True

def Square_And_Multiply(x, k, p):
    #二進制數字
    b = bin(k).lstrip('0b')
    r = 1
    for i in b:
        r = (r ** 2) % p
        if i == '1':
            r = (r * x) % p
    return r

def Chinese_Remainder_Theorem(ciphertext, p, q, d):
    dp = d % (p - 1)
    dq = d % (q - 1)
    qinv = modinv(q, p)

    m1 = Square_And_Multiply(ciphertext, dp, p)
    m2 = Square_And_Multiply(ciphertext, dq, q)
    h = (qinv * (m1 - m2)) % p
    m = m2 + h * q
    return m

def egcd(q, p):
    if q == 0:
        return (p, 0, 1)
    else:
        g, y, x = egcd(p % q, q)
        return (g, x - (p // q) * y, y)

def modinv(q, p):
    g, x, y = egcd(q, p)
    return x % p

def inverse_d(e, phi_n):
    d, x, y, z, temp_phi = 0, 0, 1, 1, phi_n
    while e > 0:
        temp1 = int(temp_phi/e)
        temp2 = temp_phi - temp1 * e
        temp_phi = e
        e = temp2

        xx = y - temp1 * x
        yy = d - temp1 * z

        y, x, d, z = x, xx, z, yy
    #找到d
    if temp_phi == 1:
        return (d + phi_n)%phi_n

def RSA(n, plaintext):
    pl = int(n / 2) + 1
    ql = int((n / 2) + (n % 2))
    p = prime_number(pl)
    q = prime_number(ql)
    while p == q:
        q = prime_number(ql)
    n = p * q
    phi_n = (p - 1) * (q - 1)
    #找e
    while True:
        e = randrange(1, phi_n-1)
        if math.gcd(e, phi_n) == 1:
            #找d
            d = inverse_d(e, phi_n)
            break
    print("p = %d\nq = %d\nn = %d\ne = %d\nd = %d" %(p,q,n,e,d))

    cipher = [Square_And_Multiply(ord(cipher), e, n) for cipher in plaintext]
    #清空明文
    plaintext = ''
    for plain in cipher:
        plaintext += chr(Chinese_Remainder_Theorem(plain, p, q, d))
    print(cipher)
    print(plaintext)

def random_number(length):
    num = getrandbits(length)
    #設最高位和最低位為1
    num |= (1 << length - 1) | 1
    return num

def prime_number(length):
    p = 4
    #確認質數生成方式並生成質數回傳
    while not Miller_Rabin(p, 128):
        p = random_number(length)
    return p

#main
if len(sys.argv) == 3:
    n = int(sys.argv[1])
    plaintext = str(sys.argv[2])
    if n < 7:
        print('n need great than 7 bits')
    else:
        RSA(n, plaintext)
