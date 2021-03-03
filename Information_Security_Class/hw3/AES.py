import sys, cv2, math
import numpy as np
import operator
from Crypto.Cipher import AES
from Crypto.Util.number import bytes_to_long
from PIL import Image

# 圖片存檔
def savepicture(img):
    cv2.imwrite('test' + imgname, img)

# 顯示圖片 按任意鍵關閉
def showpicture(img):
    cv2.imshow('Image', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# ECB輸出加密後圖片及解密圖片
def ECB(img, key):
    x, y, z = img.shape
    w = (16 - ((x * y * z) % 16)) % 16
    #paddimg
    if w > 0 :
        img = img.reshape(-1)
        a = np.zeros(w)
        img = np.append(img, a)
        img = img.astype(np.uint8)
    img = img.reshape(-1, 16)
    
    ciphertext= ECBencrypt(img, key)
    cipherpicture = np.resize(ciphertext, (x, y, z))
    
    img = ciphertext.reshape(-1, 16)
    decrypttext = ECBdecrypt(img, key)
    decryptpicture = np.resize(decrypttext, (x, y, z))

    showpicture(cipherpicture)
    showpicture(decryptpicture)

# CBC輸出加密後圖片及解密圖片
def CBC(img, key, iv):
    x, y, z = img.shape
    w = (16 - ((x * y * z) % 16)) % 16
    #paddimg
    if w > 0:
        img = img.reshape(-1)
        a = np.zeros(w)
        img = np.append(img, a)
        img = img.astype(np.uint8)
    img = img.reshape(-1, 16)

    ciphertext = CBCencrypt(img, key, iv)
    cipherpicture = np.resize(ciphertext, (x, y, z))

    img = ciphertext.reshape(-1, 16)
    decrypttext = CBCdecrypt(img, key, iv)
    decryptpicture = np.resize(decrypttext, (x, y, z))

    showpicture(cipherpicture)
    showpicture(decryptpicture)

# OFB輸出加密後圖片及解密圖片
def OFB(img, key, iv):
    x, y, z = img.shape
    w = (16 - ((x * y * z) % 16)) % 16
    #paddimg
    if w > 0:
        img = img.reshape(-1)
        a = np.zeros(w)
        img = np.append(img, a)
        img = img.astype(np.uint8)
    img = img.reshape(-1, 16)

    ciphertext = OFBencrypt(img, key, iv)
    cipherpicture = np.resize(ciphertext, (x, y, z))

    img = ciphertext.reshape(-1, 16)
    decrypttext = OFBdecrypt(img, key, iv)
    decryptpicture = np.resize(decrypttext, (x, y, z))

    showpicture(cipherpicture)
    showpicture(decryptpicture)

# ECB加密
def ECBencrypt(img,key):
    cipher = AES.new(key, AES.MODE_ECB)
    ciphertext = b""
    for plain in img:
        plaintext = plain.tobytes()
        ciphertext += bytes(cipher.encrypt(plaintext))
    ciphertext = np.frombuffer(ciphertext, dtype=img.dtype)
    return ciphertext

# ECB解密
def ECBdecrypt(img, key):
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = b""
    for pcipher in img:
        ciphertext = pcipher.tobytes()
        plaintext += bytes(cipher.decrypt(ciphertext)) 
    plaintext = np.frombuffer(plaintext, dtype=img.dtype)
    return plaintext

# CBC加密
def CBCencrypt(img, key, iv):
    cipher = AES.new(key, AES.MODE_ECB)
    ciphertext = b""
    for plain in img:
        plaintext = plain.tobytes()
        plaintext = bytes(map(operator.xor, iv, plaintext))
        text = cipher.encrypt(plaintext)
        ciphertext += bytes(text)
        iv = bytes(text)
    ciphertext = np.frombuffer(ciphertext, dtype=img.dtype)
    return ciphertext

# CBC解密
def CBCdecrypt(img, key, iv):
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = b""
    for pcipher in img:
        ciphertext = pcipher.tobytes()
        plain = bytes(cipher.decrypt(ciphertext))
        plaintext += bytes(map(operator.xor, iv, plain))
        iv = ciphertext
    plaintext = np.frombuffer(plaintext, dtype=img.dtype)
    return plaintext

# OFB加密
def OFBencrypt(img, key, iv):
    cipher = AES.new(key, AES.MODE_ECB)
    ciphertext = b""
    for plain in img:
        iv = cipher.encrypt(iv)
        plaintext = plain.tobytes()
        ciphertext += bytes([a ^ b for a, b in zip(iv, plaintext)])
    ciphertext = np.frombuffer(ciphertext, dtype=img.dtype)
    return ciphertext

# OFB解密
def OFBdecrypt(img, key, iv):
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = b""
    for pcipher in img:
            iv = cipher.encrypt(iv)
            ciphertext = pcipher.tobytes()
            plaintext += bytes([a ^ b for a, b in zip(iv, ciphertext)])
    plaintext = np.frombuffer(plaintext, dtype=img.dtype)
    return plaintext

if len(sys.argv) == 3:
    imgname = sys.argv[1]
    key = sys.argv[2]
    if (len(key) > 16):
        key = key[0:16]
    if (len(key) < 16):
        key = key + ('x' * (16 - len(key) % 16))
if len(sys.argv) == 2:
    key = 'hellomynameiskey'
    imgname = sys.argv[1]
if len(sys.argv) < 2:
    key = 'hellomynameiskey'
    imgname = 'linux.jpg'

cipherpicture = cv2.imread(imgname)
key = bytes(key, encoding = 'utf8')
iv = bytes('hellothisisaaaiv', encoding = 'utf8')

ECB(cipherpicture,key)   
CBC(cipherpicture,key,iv)
OFB(cipherpicture,key,iv)
