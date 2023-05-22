a, b, c = map(int, (input().split()))

last = a + (c - 1) * b
soma = ((a + last) * c) // 2

print(soma)