mask = "111101X010011110100100110100101X0X0X"
c=1010356

l = len(mask) - 1
a = list(map(lambda x: x == '1', list(mask)))
b = list(map(lambda x: x == '0', list(mask)))

total_a = 0
total_b = 0
for i in range(len(a)):
    if a[i]:
        total_a += (1 << l - i)
for i in range(len(b)):
    if b[i]:
        total_b += (1 << l - i)


print(bin(c))
print(bin(total_a))
print(bin(total_b))
print(total_a, total_b)
c |= total_a
print('here', bin(c))
print(c)

c &= ~total_b
print(c)
print('here', bin(c))