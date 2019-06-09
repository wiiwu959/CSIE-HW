def hanoi(n, a='A', b='B', c='C'):
    if n == 1:
        print('move', a, '-->', c)
        return
    hanoi(n-1, a, c, b)
    print('move', a, '-->', c)
    hanoi(n-1, b, a, c)

print(hanoi(5))