n = int(raw_input())
step = int(raw_input())

last = 0
for i in range(n):
    last = (last + step ) % i
print last + 1