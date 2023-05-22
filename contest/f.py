import math as m

numbers = [int(x) for x in input().split()]

gcd = numbers.pop(0)
for elem in numbers:
    gcd = m.gcd(gcd, elem)
print(gcd)